//прямое слияние

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <vector>

bool checkRead(std::ifstream &reader, const std::string &fileName)
{
	if (!reader.is_open()) {
		std::cout << "Can't open " << fileName << "!" << std::endl;
		return false;
	}
	return true;
}

bool checkWrite(std::ofstream &writer, const std::string &fileName)
{
	if (!writer.is_open()) {
		std::cout << "Can't create " << fileName << "!" << std::endl;
		return false;
	}
	return true;
}

bool fileRead(const std::string &fileName)
{
	std::ifstream reader;

	reader.open(fileName);

	if (!checkRead(reader, fileName))
	{
		return false;
	}

	char tmp;
	while (reader.get(tmp))
	{
		std::cout << tmp;
	}
	std::cout << std::endl;

	reader.close();
	return true;
}

bool createFileWithRandomNumbers(const std::string &fileName, const int numbersCount, const int maxNumberValue)
{
	std::ofstream writer;

	writer.open(fileName);

	if (!checkWrite(writer, fileName)) {
		return false;
	}

	std::mt19937 gen(time(0));

	for (int i = 0; i < numbersCount; ++i)
	{
		std::uniform_int_distribution<> uid(0, maxNumberValue);
		writer << uid(gen);
		writer << " ";
	}
	writer.close();

	return true;
}

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

bool isFileContainsSortedArray(const std::string &fileName)
{
	std::ifstream reader;

	reader.open(fileName);

	if (!checkRead(reader, fileName))
	{
		return false;
	}

	int tmp;
	reader >> tmp;

	while (!isEmpty(reader))
	{
		int tmp2 = tmp;
		reader >> tmp;

		if (tmp2 > tmp)
		{
			reader.close();
			return false;
		}
	}

	reader.close();
	return true;
}

bool fragmentation(std::string file_1, std::string file_2, std::string file_3)
{
	std::ifstream reader;
	std::ofstream writer_1, writer_2;

	reader.open(file_1);
	if (!checkRead(reader, file_1))
	{
		return false;
	}

	writer_1.open(file_2);
	writer_2.open(file_3);
	if (!checkWrite(writer_1, file_2) || !checkWrite(writer_2, file_3))
	{
		return false;
	}

	int tmp_1, tmp_2, numberFile = 0;
	std::vector<std::ofstream *> fileWriteNow;
	fileWriteNow.push_back(&writer_1);
	fileWriteNow.push_back(&writer_2);

	reader >> tmp_1;

	while (!isEmpty(reader))
	{
		*fileWriteNow[numberFile] << tmp_1;
		*fileWriteNow[numberFile] << " ";

		reader >> tmp_2;
		if (tmp_1 > tmp_2)
		{
			numberFile = 1 - numberFile;
		}
		tmp_1 = tmp_2;
	}

	writer_1.close();
	writer_2.close();
	reader.close();

	return true;
}

bool confluence(std::string file_1, std::string file_2, std::string file_3, std::string file_4)
{
	std::ifstream reader_1, reader_2;
	std::ofstream writer_1, writer_2;

	reader_1.open(file_1);
	reader_2.open(file_2);
	if (!checkRead(reader_1, file_1) || !checkRead(reader_2, file_2))
	{
		return false;
	}

	writer_1.open(file_3);
	writer_2.open(file_4);
	if (!checkWrite(writer_1, file_3) || !checkWrite(writer_2, file_4))
	{
		return false;
	}

	int tmp[2], read[2];
	std::vector<std::ofstream *> fileWrite;
	fileWrite.push_back(&writer_1);
	fileWrite.push_back(&writer_2);
	std::vector<std::ifstream *> fileRead;
	fileRead.push_back(&reader_1);
	fileRead.push_back(&reader_2);

	*fileRead[0] >> tmp[0];
	*fileRead[1] >> tmp[1];

	int numberFileIn = 0, numberFileFrom = 0;

	while (!isEmpty(reader_1) && !isEmpty(reader_2))
	{
		if (tmp[numberFileFrom] > tmp[1 - numberFileFrom])
		{
			numberFileFrom = 1 - numberFileFrom;
		}

		*fileWrite[numberFileIn] << tmp[numberFileFrom];
		*fileWrite[numberFileIn] << " ";
		*fileRead[numberFileFrom] >> read[numberFileFrom];

		if (isEmpty(*fileRead[numberFileFrom]) || tmp[numberFileFrom] > read[numberFileFrom])
		{
			numberFileFrom = 1 - numberFileFrom;
			*fileWrite[numberFileIn] << tmp[numberFileFrom];
			*fileWrite[numberFileIn] << " ";
			*fileRead[numberFileFrom] >> read[numberFileFrom];

			while (!isEmpty(*fileRead[numberFileFrom]) && tmp[numberFileFrom] <= read[numberFileFrom])
			{
				tmp[numberFileFrom] = read[numberFileFrom];
				*fileWrite[numberFileIn] << tmp[numberFileFrom];
				*fileWrite[numberFileIn] << " ";
				*fileRead[numberFileFrom] >> read[numberFileFrom];
			}

			tmp[1 - numberFileFrom] = read[1 - numberFileFrom];
			numberFileIn = 1 - numberFileIn;
		}

		tmp[numberFileFrom] = read[numberFileFrom];
	}

	while (!isEmpty(*fileRead[0]))
	{
		*fileWrite[numberFileIn] << tmp[0];
		*fileWrite[numberFileIn] << " ";
		*fileRead[0] >> read[0];

		if (tmp[0] > read[0])
		{
			numberFileIn = 1 - numberFileIn;
		}

		tmp[0] = read[0];
	}

	while (!isEmpty(*fileRead[1]))
	{
		*fileWrite[numberFileIn] << tmp[1];
		*fileWrite[numberFileIn] << " ";
		*fileRead[1] >> read[1];

		if (tmp[1] > read[1])
		{
			numberFileIn = 1 - numberFileIn;
		}

		tmp[1] = read[1];
	}

	reader_1.close();
	reader_2.close();
	writer_1.close();
	writer_2.close();

	return true;
}

std::string naturalSort(const std::string &fileName)
{
	int size = 1;
	std::string file_1 = "file_1.txt", file_2 = "file_2.txt", file_3 = "file_3.txt", file_4 = "file_4.txt";

	fragmentation(fileName, file_1, file_2);

	std::ifstream reader(file_2);
	if (!checkRead(reader, file_2))
	{
		return false;
	}

	while (!isEmpty(reader))
	{
		reader.close();

		confluence(file_1, file_2, file_3, file_4);

		reader.open(file_4);
		if (!checkRead(reader, file_4))
		{
			return false;
		}

		if (isEmpty(reader))
		{
			reader.close();
			return file_3;
		}

		reader.close();

		confluence(file_3, file_4, file_1, file_2);

		reader.open(file_2);
		if (!checkRead(reader, file_2))
		{
			return false;
		}

	}
	reader.close();

	return file_1;
}

int createAndSortFile(const std::string &fileName, const int numbersCount, const int maxNumberValue)
{
	if (!createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
		return -1;
	}

	std::string sortFileName;
	sortFileName = naturalSort(fileName); //Вызов функции сортировки

	if (!isFileContainsSortedArray(sortFileName)) {
		return -2;
	}

	return 1;
}

int main()
{
	std::string file = "file.txt";
	const int numbersCount = 100000;
	const int maxNumberValue = 100000;

	for (int i = 0; i < 10; i++)
	{
		switch (createAndSortFile(file, numbersCount, maxNumberValue))
		{
		case 1:
			std::cout << "Test passed." << std::endl;
			break;

		case -1:
			std::cout << "Test failed: can't create file." << std::endl;
			break;

		case -2:
			std::cout << "Test failed: file isn't sorted." << std::endl;
			break;
		}
	}

	return 0;
}
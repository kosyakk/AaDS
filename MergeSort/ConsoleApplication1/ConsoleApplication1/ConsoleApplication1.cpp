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

bool fragmentation(std::string file_1, std::string file_2, std::string file_3, int size)
{
	std::ifstream reader;
	std::ofstream writer_1(file_2), writer_2(file_3);

	if (!checkWrite(writer_1, file_1) || !checkWrite(writer_2, file_2)) {
		return false;
	}
	reader.open(file_1);
	if (!checkRead(reader, file_1))
	{
		return false;
	}

	int tmp;
	reader >> tmp;
	int numberFile = 0;
	std::vector<std::ofstream *> writeFile;
	writeFile.push_back(&writer_1);
	writeFile.push_back(&writer_2);

	while (!isEmpty(reader))
	{
		int i = 0;

		while (!isEmpty(reader) && i < size)
		{
			*writeFile[numberFile] << tmp;
			*writeFile[numberFile] << " ";
			reader >> tmp;
			++i;
		}
		numberFile = 1 - numberFile;
	}

	reader.close();
	writer_1.close();
	writer_2.close();

	return true;
}

bool confluence(std::string file_1, std::string file_2, std::string file_3, std::string file_4, int size)
{
	std::ifstream reader_1, reader_2;
	std::ofstream writer_1, writer_2;

	writer_1.open(file_3);
	writer_2.open(file_4);
	if (!checkWrite(writer_1, file_3) || !checkWrite(writer_2, file_4))
	{
		return false;
	}

	reader_1.open(file_1);
	reader_2.open(file_2);
	if (!checkRead(reader_1, file_1) || !checkRead(reader_2, file_2))
	{
		return false;
	}

	std::vector<std::ofstream *> writeFile;
	writeFile.push_back(&writer_1);
	writeFile.push_back(&writer_2);

	int tmp_1, tmp_2;
	reader_1 >> tmp_1;
	reader_2 >> tmp_2;

	int numberFile = 0;

	while (!isEmpty(reader_1) && !isEmpty(reader_2))
	{
		int i = 0, j = 0;
		while (!isEmpty(reader_1) && !isEmpty(reader_2) && i < size && j < size)
		{
			if (tmp_1 < tmp_2)
			{
				*writeFile[numberFile] << tmp_1;
				*writeFile[numberFile] << " ";
				reader_1 >> tmp_1;
				++i;
			}
			else
			{
				*writeFile[numberFile] << tmp_2;
				*writeFile[numberFile] << " ";
				reader_2 >> tmp_2;
				++j;
			}
		}
		while (!isEmpty(reader_1) && i < size)
		{
			*writeFile[numberFile] << tmp_1;
			*writeFile[numberFile] << " ";
			reader_1 >> tmp_1;
			++i;
		}
		while (!isEmpty(reader_2) && j < size)
		{
			*writeFile[numberFile] << tmp_2;
			*writeFile[numberFile] << " ";
			reader_2 >> tmp_2;
			++j;
		}
		numberFile = 1 - numberFile;
	}

	while (!isEmpty(reader_1))
	{
		*writeFile[numberFile] << tmp_2;
		*writeFile[numberFile] << " ";
		reader_1 >> tmp_1;
	}

	while (!isEmpty(reader_2))
	{
		*writeFile[numberFile] << tmp_2;
		*writeFile[numberFile] << " ";
		reader_2 >> tmp_2;
	}

	reader_1.close();
	reader_2.close();
	writer_1.close();
	writer_2.close();

	return true;
}

std::string mergeSort(const std::string &fileName)
{
	int size = 1;
	std::string file_1 = "file_1.txt", file_2 = "file_2.txt", file_3 = "file_3.txt", file_4 = "file_4.txt";

	fragmentation(fileName, file_1, file_2, size);
	
	std::ifstream reader(file_2);
	if (!checkRead(reader, file_2))
	{
		return false;
	}

	while (!isEmpty(reader))
	{
		reader.close();

		confluence(file_1, file_2, file_3, file_4, size);

		size *= 2;

		confluence(file_3, file_4, file_1, file_2, size);

		size *= 2;

		reader.open(file_2);
		if (!checkRead(reader, file_2))
		{
			return false;
		}

	}
	reader.close();

	return file_2;
}

int createAndSortFile(const std::string &fileName, const int numbersCount, const int maxNumberValue)
{
	if (!createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
		return -1;
	}

	std::string sortFileName;
	sortFileName = mergeSort(fileName); //Вызов функции сортировки

	if (!isFileContainsSortedArray(sortFileName)) {
		return -2;
	}

	return 1;
}

int main()
{
	std::string file = "file.txt";
	const int numbersCount = 1000000;
	const int maxNumberValue = 1000000;

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
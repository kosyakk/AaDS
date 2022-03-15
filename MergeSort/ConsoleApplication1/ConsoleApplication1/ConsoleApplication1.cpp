//прямое слияние

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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

bool fileRead(std::string &fileName)
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

	srand(time(0));

	for (int i = 0; i < numbersCount; ++i)
	{
		writer << rand() % maxNumberValue;
		writer << " ";
	}
	writer.close();

	return true;
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

	while (!reader.eof())
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
	while (!reader.eof())
	{
		int i = 0;
		
			while (!reader.eof() && i < size)
			{
				if (numberFile == 0)
				{
					writer_1 << tmp;
					writer_1 << " ";
				}
				else
				{
					writer_2 << tmp;
					writer_2 << " ";
				}
				
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
	std::ofstream writer_1(file_3), writer_2(file_4);
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

	int tmp_1, tmp_2;
	reader_1 >> tmp_1;
	reader_2 >> tmp_2;

	int numberFile = 0, k = 0;

	while (!reader_1.eof() && !reader_2.eof())
	{
		int i = 0, j = 0;
		while (!reader_1.eof() && !reader_2.eof() && i < size && j < size)
		{
			if (tmp_1 < tmp_2)
			{
				if (numberFile == 0)
				{
					writer_1 << tmp_1;
					writer_1 << " ";
				}
				else
				{
					writer_2 << tmp_1;
					writer_2 << " ";
				}
				reader_1 >> tmp_1;
				++i;
			}
			else
			{
				if (numberFile == 0)
				{
					writer_1 << tmp_2;
					writer_1 << " ";
				}
				else
				{
					writer_2 << tmp_2;
					writer_2 << " ";
				}
				reader_2 >> tmp_2;
				++j;
			}
		}
		while (!reader_1.eof() && i < size)
		{
			if (numberFile == 0)
			{
				writer_1 << tmp_1;
				writer_1 << " ";
			}
			else
			{
				writer_2 << tmp_1;
				writer_2 << " ";
			}
			reader_1 >> tmp_1;
			++i;
		}
		while (!reader_2.eof() && j < size)
		{
			if (numberFile == 0)
			{
				writer_1 << tmp_2;
				writer_1 << " ";
			}
			else
			{
				writer_2 << tmp_2;
				writer_2 << " ";
			}
			reader_2 >> tmp_2;
			++j;
		}
		numberFile = 1 - numberFile;
	}

	while (!reader_1.eof())
	{
		if (numberFile == 0)
		{
			writer_1 << tmp_2;
			writer_1 << " ";
		}
		else
		{
			writer_2 << tmp_2;
			writer_2 << " ";
		}
		reader_1 >> tmp_1;
	}

	while (!reader_2.eof())
	{
		if (numberFile == 0)
		{
			writer_1 << tmp_2;
			writer_1 << " ";
		}
		else
		{
			writer_2 << tmp_2;
			writer_2 << " ";
		}
		reader_2 >> tmp_2;
	}

	reader_1.close();
	reader_2.close();
	writer_1.close();
	writer_2.close();

	return true;
}

bool mergeSort(const std::string &fileName)
{
	int size = 1;
	std::string file_1 = "file_1.txt", file_2 = "file_2.txt", file_3 = "file_3.txt", file_4 = "file_4.txt";

	/*std::ifstream reader_1, reader_2;
	std::ofstream writer_1, writer_2;

	reader_1.open(fileName);
	if (!checkRead(reader_1, fileName))
	{
		return false;
	}
	writer_1.open(file_1);
	writer_2.open(file_2);
	if (!checkWrite(writer_1, file_1) || !checkWrite(writer_2, file_2)) {
		return false;
	}*/

	fragmentation(fileName, file_1, file_2, size);

	/*reader_1.close();
	writer_1.close();
	writer_2.close();*/
	
	std::ifstream reader;
	reader.open(file_2);
	if (!checkRead(reader, file_2))
	{
		return false;
	}while (!reader.eof())
	{
		reader.close();

		confluence(file_1, file_2, file_3, file_4, size);

		std::cout << "1:" << std::endl;
		fileRead(file_1);
		std::cout << std::endl;
		fileRead(file_2);
		std::cout << std::endl;
		fileRead(file_3);
		std::cout << std::endl;
		fileRead(file_4);
		std::cout << std::endl;

		size *= 2;

		confluence(file_3, file_4, file_1, file_2, size);

		std::cout << "2:" << std::endl;
		fileRead(file_3);
		std::cout << std::endl;
		fileRead(file_4);
		std::cout << std::endl;
		fileRead(file_1);
		std::cout << std::endl;
		fileRead(file_2);
		std::cout << std::endl;

		size *= 2;

		reader.open(file_2);
		fileRead(file_2);
		if (!checkRead(reader, file_2))
		{
			return false;
		}

	}

	reader.close();

	return true;
}

int createAndSortFile(const std::string &fileName, const int numbersCount, const int maxNumberValue)
{
	if (!createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
		return -1;
	}

	mergeSort(fileName); //Вызов функции сортировки

	if (!isFileContainsSortedArray(fileName)) {
		return -2;
	}

	return 1;
}

int main()
{
	std::string file = "file.txt", file_1 = "file_1.txt", file_2 = "file_2.txt", file_3 = "file_3.txt", file_4 = "file_4.txt";
	const int numbersCount = 10;
	const int maxNumberValue = 100;

	createFileWithRandomNumbers(file, numbersCount, maxNumberValue);
	fileRead(file);
	std::cout << std::endl;

	mergeSort(file);

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
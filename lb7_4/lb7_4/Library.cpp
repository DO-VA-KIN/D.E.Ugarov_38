#include "pch.h"
#include "Library.h"


Library::Library(int countBooks, int countVisitors)
{
	Books.reserve(countBooks);
	for (int i = 0; i < countBooks; i++)
	{
		Book book(i);
		Books.push_back(book);
	}

	Visitors.reserve(countVisitors);
	for (int i = 0; i < countVisitors; i++)
	{
		Visitor visitor(i);
		Visitors.push_back(visitor);
	}

	Report.Books.resize(countBooks);
	vector<string> authors;
	for (int i = 0; i < countBooks; i++)
	{
		Report.Books[i].Name = Books[i].Name;
		bool flag = false;
		for (int k = 0; k <authors.size(); k++)
			if (authors[k] == Books[i].Author) flag = true;
		if (!flag)
			authors.push_back(Books[i].Author);
	}

	Report.Authors.resize(authors.size());
	for (int i = 0; i < authors.size(); i++)
		Report.Authors[i].Author = authors[i];



}


void Library::SelectBook()
{
	
}


void Library::Work(int timeW)
{
	for (int i = 0; i < timeW; i++)
	{

		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		int rand1 = 0 + rand() % (5 - 0 + 1);
		for (int k = 0; k < rand1; k++)
		{
			srand(time(NULL) + k+i);
			int rand2 = 0 + rand() % (Visitors.size());
			if (!Visitors[rand2].IsReadNow())
			{
				for (int j = 0; j < Books.size(); j++)//перебираем книги
				{
					//отбираем доступные(невзятые) и удовлетворяющие запросам посетителя
					if (Books[j].Enabed && Visitors[rand2].Age > Books[j].Age && Books[j].Type == Visitors[rand2].Type &&
						Books[j].Size < Visitors[rand2].MaxSize && Books[j].Size > Visitors[rand2].MinSize)
					{
						Books[j].Enabed = false;
						int res = Visitors[rand2].SetBook(Books[j].Name, Books[j].Size);
						Report.Books[j].CountRead++;//формируем отчет
						if (res != -1)
						{
							if (Report.Books[j].TimeRead == 0)
								Report.Books[j].TimeRead += res;
							else Report.Books[j].TimeRead = round((Report.Books[j].TimeRead + res) / 2);
						}
						for (int ii = 0; ii < Report.Authors.size(); ii++)
						{
							if (Report.Authors[ii].Author == Books[j].Author)
							{ Report.Authors[ii].CountRead++; break; }
						}
						break;
					}
				}
			}
			//else rand1++;

		}



		for (int k = 0; k < Visitors.size(); k++)
		{
			if (Visitors[k].IsReadNow())
			{
				int res = Visitors[k].Read(k+i);
				if (res != -1)
				{
					for (int j = 0; j < Books.size(); j++)
					{
						if (Visitors[k].ReadBooks.size() == 0) break;

						if (Books[j].Name == Visitors[k].ReadBooks[Visitors[k].ReadBooks.size() - 1])
						{
							if (Report.Books[j].Rating == 0)
								Report.Books[j].Rating += res;
							else Report.Books[j].Rating = (Report.Books[j].Rating + res) / 2;
							Books[j].Enabed = true;

							srand(time(NULL) + 3 * i);
							int rand1 = 0 + rand() % 3;
							switch (rand1)
							{
							case 0:
								Visitors[k].MinSize = 0;
								Visitors[k].MaxSize = 99;
								break;
							case 1:
								Visitors[k].MinSize = 100;
								Visitors[k].MaxSize = 500;
								break;
							case 2:
								Visitors[k].MinSize = 501;
								Visitors[k].MaxSize = 99999;
								break;
							default:
								//посетитель любит бокс, а не читать
								Visitors[k].MinSize = 0;
								Visitors[k].MaxSize = 0;
								break;
							}

							srand(time(NULL) + 3 * i);
							int rand2 = 0 + rand() % 6;
							switch (rand1)
							{
							case 0: Visitors[k].Type = "Детектив"; break;
							case 1: Visitors[k].Type = "Роман"; break;
							case 2: Visitors[k].Type = "Фентези"; break;
							case 3: Visitors[k].Type = "Фантастика"; break;
							case 4: Visitors[k].Type = "Историческое"; break;
							default: Visitors[k].Type = "Любой"; break;
							}
						}
					}
					
				}
			}
		}
	}
	for (int k = 0; k < Visitors.size(); k++)
	{
		while (Visitors[k].IsReadNow())
		{
			int res = Visitors[k].Read(k);
			if (res != -1)
			{
				for (int j = 0; j < Books.size(); j++)
				{
					if (Visitors[k].ReadBooks.size() == 0) break;

					if (Books[j].Name == Visitors[k].ReadBooks[Visitors[k].ReadBooks.size() - 1])
					{
						if (Report.Books[j].Rating == 0)
							Report.Books[j].Rating += res;
						else Report.Books[j].Rating = (Report.Books[j].Rating + res) / 2;
						Books[j].Enabed = true;
					}
				}
			}
		}
	}
	
}

#include "pch.h"
#include "Clinic.h"


Clinic::Clinic(int countWindows, int countVisitors)//�������� ������ (�������� ���-�� �����������)
{
	LivePriority.reserve(1500);//��������� ������ ��� �������������� ������ ������
	EnrollmentPriority.reserve(1000);

	Windows.reserve(countWindows);
	Windows = vector<Window>(countWindows);//�������� ���������� ���-�� ����

	Report.Reception.Windows.resize(countWindows);

	for (int i = 0; countVisitors > 0; i++)//��������� �����������
	{
		srand(time(NULL) + (double)i/2 - countVisitors);
		//int num = min + rand() % (max - min + 1);
		int chanceVisit = 0 + rand() % 101;

		srand(time(NULL) - (double)i/2 + countVisitors);
		int chanceEnrollment = 0 + rand() % 101;

		if (chanceVisit < ChildVisitor::VisitChance)//����
		{
			countVisitors--;//������� ������ ���-�� �����������, �������� ������� �� ����

			Visitor visitor(ChildVisitor::Type(), ChildVisitor::VisitChance,
				ChildVisitor::TimeReceipt(i), ChildVisitor::EnrollmentChance);//�������� ����������

			if (chanceEnrollment < visitor.EnrollmentChance)//�������� ������� ������
			{
				EnrollmentPriority.push_back(visitor);//���������� � ������ ���������� �����������
				Report.Queue.Enrollment.Child++;//���������� �������� ������
			}
			else
			{
				Report.Queue.Live.Child++;//���������� � ������ ����� �������
				LivePriority.push_back(visitor);//���������� �������� ������
			}
		}
		else if (chanceVisit < OldVisitor::VisitChance)//�������
		{
			countVisitors--;

			Visitor visitor(OldVisitor::Type(), OldVisitor::VisitChance,
				OldVisitor::TimeReceipt(i), OldVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Old++;
			}
			else
			{
				Report.Queue.Live.Old++;
				LivePriority.push_back(visitor);
			}
		}
		else if (chanceVisit < AdultVisitor::VisitChance)//��������
		{
			countVisitors--;

			Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
				AdultVisitor::TimeReceipt(i), AdultVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Adult++;
			}
			else
			{
				Report.Queue.Live.Adult++;
				LivePriority.push_back(visitor);
			}
		}

	}
}


void Clinic::Work(int timeWork, int breakStart, int breakEnd)//������ � ������� ��������� �������(� �������), break -�������� ��������
{
	//��������� � ��������� ���������� ������� ������ ������ size
	//(� ������������ �������� �����, �������� � �������� �-�� �� ��������)
	int windowsCount = Windows.size();//����� ����
	//������� ����������
	Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
		AdultVisitor::TimeReceipt(0), AdultVisitor::EnrollmentChance);

	for (int i = 0; i < timeWork; i++)
	{
		srand(time(NULL) + (double)i / 2);
		//int num = min + rand() % (max - min + 1);
		int chanceVisit = 0 + rand() % 101;//���� ��������� ����������

		srand(time(NULL) - (double)i / 2);
		int chanceEnrollment = 0 + rand() % 101;//���� ������ ����������

		if (chanceVisit < ChildVisitor::VisitChance)//����
		{
			Visitor visitor(ChildVisitor::Type(), ChildVisitor::VisitChance,
				ChildVisitor::TimeReceipt(i), ChildVisitor::EnrollmentChance);//�������� ����������

			if (chanceEnrollment < visitor.EnrollmentChance)//�������� ������� ������
			{
				EnrollmentPriority.push_back(visitor);//���������� � ������ ���������� �����������
				Report.Queue.Enrollment.Child++;//���������� �������� ������
			}
			else
			{
				Report.Queue.Live.Child++;//���������� � ������ ����� �������
				LivePriority.push_back(visitor);//���������� �������� ������
			}
		}
		if (chanceVisit < OldVisitor::VisitChance)//�������
		{
			Visitor visitor(OldVisitor::Type(), OldVisitor::VisitChance,
				OldVisitor::TimeReceipt(i), OldVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Old++;
			}
			else
			{
				Report.Queue.Live.Old++;
				LivePriority.push_back(visitor);
			}
		}
		if (chanceVisit < AdultVisitor::VisitChance)//��������
		{
			Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
				AdultVisitor::TimeReceipt(i), AdultVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Adult++;
			}
			else
			{
				Report.Queue.Live.Adult++;
				LivePriority.push_back(visitor);
			}
		}

		//�������
		if (i > breakStart && i < breakEnd)
		{
			if(i == breakStart + 1)
				for (int k = 0; k < windowsCount; k++)
					while (Windows[k].IsBusy());//���� ������������
			continue;
		}


		for (int k = 0; k < windowsCount; k++)
		{
			if (!Windows[k].IsBusy())//���� ���� ��������
			{
				if (EnrollmentPriority.empty() && !LivePriority.empty())//�� ������
				{
					visitor = LivePriority[0];
					LivePriority.erase(LivePriority.begin());//�������� ���������� �� �������
					if (visitor.Type == ChildVisitor::Type())//���������� ������
					{
						Report.Reception.Windows[k].Child.Count++;
						Report.Reception.Windows[k].Child.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == AdultVisitor::Type())
					{
						Report.Reception.Windows[k].Adult.Count++;
						Report.Reception.Windows[k].Adult.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == OldVisitor::Type())
					{
						Report.Reception.Windows[k].Old.Count++;
						Report.Reception.Windows[k].Old.TimeSpent += visitor.TimeReceipt;
					}
				}
				else if (!EnrollmentPriority.empty())//����� �������
				{
					visitor = EnrollmentPriority[0];
					EnrollmentPriority.erase(EnrollmentPriority.begin());
					if (visitor.Type == ChildVisitor::Type())//���������� ������
					{
						Report.Reception.Windows[k].Child.Count++;
						Report.Reception.Windows[k].Child.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == AdultVisitor::Type())
					{
						Report.Reception.Windows[k].Adult.Count++;
						Report.Reception.Windows[k].Adult.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == OldVisitor::Type())
					{
						Report.Reception.Windows[k].Old.Count++;
						Report.Reception.Windows[k].Old.TimeSpent += visitor.TimeReceipt;
					}
				}
			}
		}
	}

}



//////����\\\\\\\

bool Window::IsBusy()//������ �� ����
{
	if (LeftTime > 0)
	{
		LeftTime--;
		return true;
	}
	else return false;
}

void Window::GetVisitor(Visitor visitor)//���� ���������� �� ���������
{
	LeftTime = visitor.TimeReceipt;	
}

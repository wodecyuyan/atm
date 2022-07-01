#include<iostream>
#include<string>

using namespace std;

class account     //����һ���û���
{
public:
	account();    //���캯��
	string get_number();  //�����û�����
	string get_name();    //�����û�����
	int get_money();       //��������������
	int get_money(int m); //����ֵ
	string get_password(); //��������
	void get_password(string p);//�����븳ֵ
private:
	int money;
	string number;
	string name;
	string password;
};

account::account()
{
    cout << "��ӭʹ�ã�" << "�봴�������˻���" <<endl;
	cout << "�����뿨��:";
	cin >> number;
	cout << endl;
	cout << "�������û�����";
	cin >> name;
	cout << endl;
	cout << "������������룺";
	cin >> password;
	money = 0;
	cout << "�����ɹ���" << endl;

}

string account::get_number()
{
    return number;
}

string account::get_name()
{
    return name;
}

string account::get_password()
{
    return password;
}

void account::get_password(string p)
{
    password = p;
}

int account::get_money()
{
    return money;
}

int account::get_money(int m)
{
    money = m;
    return money;
}

class atm   //atm��
{
public:
    atm();   //���캯��
    atm(account a1);  //���캯������account���һ������������
	void enter();     //��¼
	void display();   //��ʾ����
	void deposit();   //���
	void withdraw();  //ȡ��
	void change_password();  //�޸�����
	void inquiry();   //��ѯ���
	void exit();      //�˳�ϵͳ
private:
    account a;
};

atm::atm()
{
}

atm::atm(account a1)
{
    a = a1;
}

void atm::display()
{
    int n;
    cout << "1.��¼  2.���  3.ȡ��  4.�޸�����  5.��ѯ���  6.�˳�ϵͳ"<<endl<<"��ѡ��"<<endl;
    while(cin >> n)
    {
        if(6 == n)
        {
            exit();
            break;
        }                          //��nΪ6ʱ�˳�ϵͳ��������ʾ���ܽ��棬������ѭ��
        switch(n)
        {
            case 1: enter();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: change_password();
                    break;
            case 5: inquiry();
                    break;
            default: cout << "�޴˲�����" << endl;
                    break;
        }
        cout << "1.��¼  2.���  3.ȡ��  4.�޸�����  5.��ѯ���  6.�˳�ϵͳ"<<endl<<"��ѡ��"<<endl;
    }
}
void atm::enter()
{
    string number1;
	string temp;
	int t = 0;
	cout << "�����뿨�ţ�";
	cin >> number1;
	if(a.get_number() == number1)  //�ж��Ƿ���ڴ��˻�����������ִ���������
    {
        cout << "���������룺";
        cin >> temp;
        cout << endl;
        while(a.get_password() != temp)
        {
            t++;
            if(3 == t)
            {
                cout << "�������3�Σ����ѱ���!"<< endl;
                exit();
                break;
            }          //���������3��ʱ���������˳�ϵͳ
            cout << "�������!" <<endl <<"���������룺";
            cin >> temp;    //���������ʾ�û���������
        }
        if(a.get_password() == temp)
        {
            cout << "��¼�ɹ���" << a.get_name() << "��ӭ����" << endl;
            display();
        }                  //������ȷ���¼�ɹ�����ʾ����
    }
    else
    {
        cout << "�޴��˻���" << endl;
    }            //��δ�ҵ��˿��ţ����޴��˻�
}

void atm::deposit()              //���
{
	int m;
	cout << "������������";
	cin >> m;
	cout << endl;
	a.get_money(a.get_money() + m);
}

void atm::withdraw()  //ȡ��
{
	int m;
	cout << "������ȡ������";
	cin >> m;
	if(m <= a.get_money())
	{
		a.get_money(a.get_money() - m);
	}
	else
	{
		cout << "����!"<< endl;
	}    //��ȡ�����������ʱ�����㣬������
}

void atm::change_password()  //�޸�����
{
	string temp;
	string temp1;
	string temp2;
	int t = 0;
	cout << "������ԭ���룺";
	cin >> temp;
	cout << endl;
	while(a.get_password() != temp)
	{
		t++;
		if(3 == t)
		{
			cout << "�������3�Σ����ѱ���!"<< endl;
			exit();
			break;
		}
		cout << "�������!" <<endl <<"���������룺";
		cin >> temp;
	}  //��ȷ��ԭ����
	if(a.get_password() == temp)
	{
		cout << "������������:";
		cin >> temp1;
		cout << "��ȷ������:";
		cin >> temp2;
		if(temp1 == temp2)  //�ж����������Ƿ���ͬ
		{
			a.get_password(temp1);
			cout << "�޸�����ɹ���" <<endl;
		}
		else
		{
			cout << "�������! �����²�����" << endl;
			display();
		}
	}
}
void atm::inquiry()   //��ʾ���
{
	cout << "�������Ϊ��" << a.get_money() <<"Ԫ"<<endl;
}

void atm::exit()  //�˳�ϵͳ
{
	cout << "��л����ʹ��!"<<endl;
}

int main()
{
	atm my_atm;
	my_atm.enter();
	return 0;
}

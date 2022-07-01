#include<iostream>
#include<string>

using namespace std;

class account     //定义一个用户类
{
public:
	account();    //构造函数
	string get_number();  //返回用户卡号
	string get_name();    //返回用户姓名
	int get_money();       //返回余额，不带参数
	int get_money(int m); //给余额赋值
	string get_password(); //返回密码
	void get_password(string p);//给密码赋值
private:
	int money;
	string number;
	string name;
	string password;
};

account::account()
{
    cout << "欢迎使用！" << "请创建您的账户！" <<endl;
	cout << "请输入卡号:";
	cin >> number;
	cout << endl;
	cout << "请输入用户名：";
	cin >> name;
	cout << endl;
	cout << "请输入你的密码：";
	cin >> password;
	money = 0;
	cout << "创建成功！" << endl;

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

class atm   //atm类
{
public:
    atm();   //构造函数
    atm(account a1);  //构造函数，用account类的一个对象作参数
	void enter();     //登录
	void display();   //显示功能
	void deposit();   //存款
	void withdraw();  //取款
	void change_password();  //修改密码
	void inquiry();   //查询余额
	void exit();      //退出系统
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
    cout << "1.登录  2.存款  3.取款  4.修改密码  5.查询余额  6.退出系统"<<endl<<"请选择："<<endl;
    while(cin >> n)
    {
        if(6 == n)
        {
            exit();
            break;
        }                          //当n为6时退出系统，不再显示功能界面，则跳出循环
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
            default: cout << "无此操作！" << endl;
                    break;
        }
        cout << "1.登录  2.存款  3.取款  4.修改密码  5.查询余额  6.退出系统"<<endl<<"请选择："<<endl;
    }
}
void atm::enter()
{
    string number1;
	string temp;
	int t = 0;
	cout << "请输入卡号：";
	cin >> number1;
	if(a.get_number() == number1)  //判断是否存在此账户，若存在则执行下面语句
    {
        cout << "请输入密码：";
        cin >> temp;
        cout << endl;
        while(a.get_password() != temp)
        {
            t++;
            if(3 == t)
            {
                cout << "密码错误3次，卡已被锁!"<< endl;
                exit();
                break;
            }          //当密码错误3次时，锁卡，退出系统
            cout << "密码错误!" <<endl <<"请重新输入：";
            cin >> temp;    //密码错误，提示用户重新输入
        }
        if(a.get_password() == temp)
        {
            cout << "登录成功！" << a.get_name() << "欢迎您！" << endl;
            display();
        }                  //密码正确则登录成功，显示功能
    }
    else
    {
        cout << "无此账户！" << endl;
    }            //若未找到此卡号，则无此账户
}

void atm::deposit()              //存款
{
	int m;
	cout << "请输入存款数：";
	cin >> m;
	cout << endl;
	a.get_money(a.get_money() + m);
}

void atm::withdraw()  //取款
{
	int m;
	cout << "请输入取款数：";
	cin >> m;
	if(m <= a.get_money())
	{
		a.get_money(a.get_money() - m);
	}
	else
	{
		cout << "余额不足!"<< endl;
	}    //当取款数大于余额时，余额不足，不操作
}

void atm::change_password()  //修改密码
{
	string temp;
	string temp1;
	string temp2;
	int t = 0;
	cout << "请输入原密码：";
	cin >> temp;
	cout << endl;
	while(a.get_password() != temp)
	{
		t++;
		if(3 == t)
		{
			cout << "密码错误3次，卡已被锁!"<< endl;
			exit();
			break;
		}
		cout << "密码错误!" <<endl <<"请重新输入：";
		cin >> temp;
	}  //先确认原密码
	if(a.get_password() == temp)
	{
		cout << "请输入新密码:";
		cin >> temp1;
		cout << "请确认密码:";
		cin >> temp2;
		if(temp1 == temp2)  //判断两次输入是否相同
		{
			a.get_password(temp1);
			cout << "修改密码成功！" <<endl;
		}
		else
		{
			cout << "密码错误! 请重新操作。" << endl;
			display();
		}
	}
}
void atm::inquiry()   //显示余额
{
	cout << "您的余额为：" << a.get_money() <<"元"<<endl;
}

void atm::exit()  //退出系统
{
	cout << "感谢您的使用!"<<endl;
}

int main()
{
	atm my_atm;
	my_atm.enter();
	return 0;
}

# 面向对象
- 基础设施
    - 不完全面向对象
        ```C
            #include <Iostream>
            using namespace std;
            
            class TestClass
            {
                public:
                    TestClass();
                    friend void setnum(TestClass &t,int n);
                    ~TestClass();
                private:
                    int num;
            };

            TestClass::TestClass()
            {
                cout<<"TestClass constructor"<<endl;
            }
            
            TestClass::~TestClass()      //析构函数在RAII等技巧中广泛使用
            {                            //而在Java中没有这个概念，C#中虽有但通常并不建议使用
                cout<<"TestClass destructor"<<endl;
            }
            
            void setnum(TestClass &t,int n)
            {
                t.num=n;                 //“友元”特性使一个外部方法给私有成员数据赋值
            }
            
            TestClass Ts;                //存在class之外的global数据
            int main()                   //main函数不在任何class内
            {
                setnum(Ts,100);          //“友元”的概念打破了传统的封装
                std::setnum(Ts,250);     //::标识符用于访问class之外的方法
                return 0;
            }
        ```
- 封装
    - 字段无默认初始化，初始值不定
    ```C
    char revBuf[100];
    printf("%s", revBuf);
    ```
    ↓↓↓↓↓↓↓↓↓↓↓↓
    ```
    烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫....
    ```
    - 可为class声明友元，友元可访问class的私有数据
    - ::标识符用于访问class之外的方法
- 多态
    - 方法和大部分操作符都可重载
    ```C
     bool operator <(const int& d)
      {
         if(num < d.num)
         {
            return true;
         }
         if(num == d.num)
         {
            return true;
         }
         return false;
      }
    ```
    - 使用virtual标记可被重载的方法(虚方法),java中无此概念,C#有
    ```C
    #include<iostream> 
    using namespace std;
    class A{
    public:
         virtual  void  display(){  cout<<"A"<<endl; }
         };
    class B :  public A{
    public:
         void  display(){ cout<<"B"<<endl;}
         };
    void doDisplay(A *p)
    {
        p->display();
        delete p;
    }
    int main(int argc,char* argv[])
    {
        doDisplay(new B());
        return 0;
    }
    ```
- 继承
    - 三种继承:public,protect,private
    - 无统一的继承树。对比C#等一切都基于Object.
    - 支持多继承，可有多个父类
    ```C
    class Derived : public B1, public B2
    {
    private:
        int d_;
    public:
        //构造函数，先调用B1的，在调用B2的，最后调用Derived的
        Derived(int b1 = 0, int b2 = 0, int d = 0) : B1(b1), B2(b2)
        {
            d_ = d;
            cout << "调用Derived的构造函数" << endl;
        }
        //析构函数的调用顺序和构造函数的相反
        ~Derived(){}
        void print()
        {
            cout << "b1_ : " << b1_ << " b2_ : " << b2_ << " d_ : " << d_ << endl;
        }
    };
    ```

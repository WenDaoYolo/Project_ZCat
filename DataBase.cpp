#include "../include/DataBase.h"

void SetCursor(int flag){                         
   CONSOLE_CURSOR_INFO cursor_info = {1, flag};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

DataBase::DataBase()
{
    this->length=0;
    this->base=new Node;
    this->base->next=NULL;
    this->state=wait;

    (this->base->data).id=0;
    (this->base->data).age=0;

    strcpy((this->base->data).name,"NULL");
    strcpy((this->base->data).email,"NULL");
    strcpy((this->base->data).address,"NULL");
    strcpy((this->base->data).sex,"NULL");
    strcpy((this->base->data).phonenumber,"NULL");
}

DataBase::~DataBase()
{
    Node* tmp;
    while(this->base!=NULL)
    {   
        tmp=this->base;
        this->base=this->base->next;
        delete tmp;
    }
}

void DataBase::ClearBuffer()
{
    std::cin.clear();
    std::cin.ignore(TOTAL_BUFFER,'\n');
}

bool DataBase::CheckInputError()
{
    if(std::cin.fail())
        return true;
    return false;
}

bool DataBase::CheckEmpty()
{
    if(this->length==0)
        return true;
    return false;
}

bool DataBase::CheckRepeatData(int id)
{
    Node* find=this->base->next;
    while(find!=NULL)
    {
        if(find->data.id==id)
            return true;
        find=find->next;
    }
    return false;
}

void DataBase::Input(Node* tmp)
{
    while(true)
    {
        std::cout<<"请输入[id 姓名 性别 年龄 手机号 电子邮箱 地址]>";
        std::cin>>tmp->data.id>>tmp->data.name>>tmp->data.sex>>tmp->data.age
        >>tmp->data.phonenumber>>tmp->data.email>>tmp->data.address;

        if(this->CheckInputError())
        {
            this->ClearBuffer();
            std::cout<<"输入数据有误，请重新输入！"<<std::endl;
        }
        else if(this->CheckRepeatData(tmp->data.id))
        {
            this->ClearBuffer();
            std::cout<<"输入的ID已存在!"<<std::endl;
        }
        else
            break;
    }
}

void DataBase::FlushScreen()
{
    SetCursor(0);   
    system("cls");//刷新控制台时光标的跳转会造成闪烁效果，刷新前先隐藏光标刷新后再显示光标
    this->DisplayMenu();
    SetCursor(1);
}

void DataBase::AddNode(Node* tmp)
{   
    Node* node=new Node;
    node->data.id=tmp->data.id;
    node->data.age=tmp->data.age;
    strcpy(node->data.name,tmp->data.name);
    strcpy(node->data.sex,tmp->data.sex);
    strcpy(node->data.phonenumber,tmp->data.phonenumber);
    strcpy(node->data.email,tmp->data.email);
    strcpy(node->data.address,tmp->data.address);

    node->next=this->base->next;
    this->base->next=node;
    this->length++;
}

void DataBase::DeleteNode()
{
    int id;
    while(true)
    {
        std::cout<<"请输入要删除记录的ID>";
        std::cin>>id;
        if(this->CheckInputError())
        {
            std::cout<<"输入错误!"<<std::endl;
            this->ClearBuffer();
        }
        else
            break;
    }

    Node* find=this->base;
    while(find->next!=NULL)
    {   
        if(find->next->data.id==id)
        {
            Node* tmp=find->next;
            find->next=find->next->next;
            delete tmp;
            this->length--;

            std::cout<<"删除成功!"<<std::endl;
            return;
        }
        find=find->next;
    }
    std::cout<<"记录不存在!"<<std::endl;
}

void DataBase::FindNode()
{
    int id;
    while(true)
    {
        std::cout<<"请输入要查找记录的ID>";
        std::cin>>id;
        if(this->CheckInputError())
        {
            std::cout<<"输入错误!"<<std::endl;
            this->ClearBuffer();
        }
        else
            break;
    }

    Node* find=this->base;
    while(find!=NULL)
    {   
        if(find->data.id==id)
        {   
            this->PrintBorder('_');
            this->PrintTable();
            this->PrintDataValue(find);
            this->PrintBorder('_');
            return;
        }
        find=find->next;
    }
    std::cout<<"记录不存在!"<<std::endl;
}

void DataBase::ChangeNode()
{
    int id;
    while(true)
    {
        std::cout<<"请输入要修改记录的ID>";
        std::cin>>id;
        if(this->CheckInputError())
        {
            std::cout<<"输入错误!"<<std::endl;
            this->ClearBuffer();
        }
        else
            break;
    }

    Node* find=this->base;
    while(find!=NULL)
    {   
        if(find->data.id==id)
        {   
            while(true)
            {
                std::cout<<"请重新输入[ID 姓名 性别 年龄 手机号 电子邮箱 地址]>";
                std::cin>>find->data.id>>find->data.name>>find->data.sex>>find->data.age
                >>find->data.phonenumber>>find->data.email>>find->data.address;

                if(this->CheckInputError())
                {
                    std::cout<<"输入数据错误！"<<std::endl;
                    this->ClearBuffer();
                }
                else
                {
                    std::cout<<"修改成功！"<<std::endl;
                    return;
                }
            }
        }
        find=find->next;
    }
    std::cout<<"记录不存在!"<<std::endl;
}
void SwapNode(Node* n1,Node* n2)
{
    Node tmp;

    tmp.data.id=n1->data.id;
    strcpy(tmp.data.name,n1->data.name);
    strcpy(tmp.data.sex,n1->data.sex);
    tmp.data.age=n1->data.age;
    strcpy(tmp.data.phonenumber,n1->data.phonenumber);
    strcpy(tmp.data.email,n1->data.email);
    strcpy(tmp.data.address,n1->data.address);

    n1->data.id=n2->data.id;
    strcpy(n1->data.name,n2->data.name);
    strcpy(n1->data.sex,n2->data.sex);
    n1->data.age=n2->data.age;
    strcpy(n1->data.phonenumber,n2->data.phonenumber);
    strcpy(n1->data.email,n2->data.email);
    strcpy(n1->data.address,n2->data.address);

    n2->data.id=tmp.data.id;
    strcpy(n2->data.name,tmp.data.name);
    strcpy(n2->data.sex,tmp.data.sex);
    n2->data.age=tmp.data.age;
    strcpy(n2->data.phonenumber,tmp.data.phonenumber);
    strcpy(n2->data.email,tmp.data.email);
    strcpy(n2->data.address,tmp.data.address);
}

int CmpById(void* e1,void* e2,CmpOrder sys)
{
    if(sys==CmpOrder::Up)
        return ((Node*)e1)->data.id-((Node*)e2)->data.id;
    else
        return -(((Node*)e1)->data.id-((Node*)e2)->data.id);
}

int CmpByName(void* e1,void* e2,CmpOrder sys)
{
    if(sys==CmpOrder::Up)
        return strcmp(((Node*)e1)->data.name,((Node*)e2)->data.name);
    else
        return -strcmp(((Node*)e1)->data.name,((Node*)e2)->data.name);
}

int CmpBySex(void* e1,void* e2,CmpOrder sys)
{
    if(sys==CmpOrder::Up)
        return strcmp(((Node*)e1)->data.sex,((Node*)e2)->data.sex);
    else
        return -strcmp(((Node*)e1)->data.sex,((Node*)e2)->data.sex);
}

int CmpByAge(void* e1,void* e2,CmpOrder sys)
{
    if(sys==CmpOrder::Up)
        return ((Node*)e1)->data.age-((Node*)e2)->data.age;
    else
        return -(((Node*)e1)->data.age-((Node*)e2)->data.age);
}

void DataBase::SortNode(CmpOrder sys,int(*cmp)(void*,void*,CmpOrder))
{
    Node* find;
    for(int i=0;i<this->length-1;i++)
    {
        find=this->base->next;
        for(int j=0;j<this->length-1-i;j++)
        {
            if(cmp(find,find->next,sys)>=0)
                SwapNode(find,find->next);
            find=find->next;
        }
    }
}

void DataBase::PrintBorder(char border_flag)
{
    for(int i=0;i<TOTAL_BUFFER+(DELIMITER_SPACE*10);i++)
        std::cout<<border_flag;
    std::cout<<std::endl;
}

void DataBase::PrintText(const char* string)
{
    for(int i=0;i<(TOTAL_BUFFER+(DELIMITER_SPACE*7))/2;i++)
        std::cout<<' ';
    std::cout<<string<<std::endl;
}

void DataBase::PrintTable()
{
    std::cout
    <<std::left<<std::setw(ID_LENGTH+DELIMITER_SPACE)<<"ID"
    <<std::left<<std::setw(NAME_BUFFER_S+DELIMITER_SPACE)<<"姓名"
    <<std::left<<std::setw(SEX_BUFFER+DELIMITER_SPACE)<<"性别"
    <<std::left<<std::setw(AGE_LENGTH+DELIMITER_SPACE)<<"年龄"
    <<std::left<<std::setw(PHONENUMBER_BUFFER+DELIMITER_SPACE)<<"手机号"
    <<std::left<<std::setw(EMAIL_BUFFER+DELIMITER_SPACE)<<"电子邮箱"
    <<std::left<<std::setw(ADDRESS_BUFFER+DELIMITER_SPACE)<<"地址"
    <<std::endl;
}

void DataBase::PrintDataValue(Node* find)
{
    std::cout
    <<std::left<<std::setw(ID_LENGTH+DELIMITER_SPACE)<<find->data.id               
    <<std::left<<std::setw(NAME_BUFFER_S+DELIMITER_SPACE)<<find->data.name
    <<std::left<<std::setw(SEX_BUFFER+DELIMITER_SPACE)<<find->data.sex
    <<std::left<<std::setw(AGE_LENGTH+DELIMITER_SPACE)<<find->data.age
    <<std::left<<std::setw(PHONENUMBER_BUFFER+DELIMITER_SPACE)<<find->data.phonenumber
    <<std::left<<std::setw(EMAIL_BUFFER+DELIMITER_SPACE)<<find->data.email
    <<std::left<<std::setw(ADDRESS_BUFFER+DELIMITER_SPACE)<<find->data.address
    <<std::endl;
}

void DataBase::DisplayMenu()
{
    this->PrintBorder('=');

    this->PrintText("数据库系统");
    this->PrintText(" 1.增加");
    this->PrintText(" 2.删除");
    this->PrintText(" 3.查找");
    this->PrintText(" 4.修改");
    this->PrintText(" 5.排序");
    this->PrintText(" 6.显示");
    this->PrintText(" 7.退出");

    this->PrintBorder('=');
}

void DataBase::DisplayInformation()
{
    if(this->CheckEmpty())
    {
        std::cout<<"数据库为空!"<<std::endl;
        return;
    }

    this->PrintBorder('_');
    this->PrintTable();

    Node* find=this->base->next;
    while(find!=NULL)
    {
        this->PrintDataValue(find);
        find=find->next;
    }

    this->PrintBorder('_');
}

bool DataBase::LoadFile(const char* filename)
{
    std::ifstream ifs;
    ifs.open(filename,std::ios::in|std::ios::binary);
    if(!ifs.is_open())
        return false;
    
    Node tmp;
    while(ifs.read((char*)&(tmp.data),sizeof(Data)))
    {
        this->AddNode(&tmp);
    }
    ifs.close();
    return true;
}

void DataBase::SaveFile(const char* filename)
{
    std::ofstream ofs;
    ofs.open(filename,std::ios::out|std::ios::binary);
    if(!ofs.is_open())
        return;
    
    Node* find=this->base->next;
    while(find!=NULL)
    {
        ofs.write((char*)&(find->data),sizeof(Data));
        find=find->next;
    }
    ofs.close();
}
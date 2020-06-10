#include<bits/stdc++.h>
using namespace std;

int main(int argc,*argv[])
{
    //read file name
    fstream in;
    fstream out;

    in.open(argv[1],ios::in);
    out.open(argv[2],ios::out);

    string a;
    int c_size,b_size,ass,algo;

    getline(in,a);
    c_size=atoi(a.c_str());
    getline(in,a);
    b_size=atoi(a.c_str());
    getline(in,a);
    ass=atoi(a.c_str());
    getline(in,a);
    algo=atoi(a.c_str());
    int blocks=c_size*1024/b_size;//有多少個blocks
    int offset=log2(b_size);//offset大小
    int index;//index大小
    int tag;//tag bits
    int tmp;
    //cout << blocks << "\n";
    switch(ass) //design cache
    {
    case 0: //dmap
    {
        long long cache[blocks];
        index=log2(blocks);//index bits
        tag=32-index-offset;//tag bits
        for(int i=0;i<blocks;i++)
            cache[i]=-1;
        while (1)
        {
            if (!getline(in,a))
            {
                break;
            }
            long long addr;
            int tags;
            int indexs;
            std::stringstream ss;
            std::stringstream gg;
            /*
            ss << std::hex << a;
            ss >> addr;
            */
            string t=a.substr(2,tag/4);
            tmp=2+tag/4;

            string ind=a.substr(tmp,index/4);

            ss<< std:: hex << t;
            ss>> tags;

            gg<< std:: hex << ind;
            gg>> indexs;
            int num=indexs%blocks;
            if(cache[num]==-1||cache[num]==tags){
                cout << -1 << endl;
                cache[num]=tags;
            }
            else{
                cout << cache[num]<< endl;
                cache[num]=tags;
            }

            //cout << indexs<< "\n";
            //cout << indexs << "\n";
            //cout << "dasd";



        }

    }
    break;
    case 1: //4-ways
    {
        int asd=blocks/4;
        long long cache1[4][asd];
        index=log2(asd);
        tag=32-index-offset;
        while (1)
        {
            if (!getline(in,a))
            {
                break;
            }
            long long addr;
            std::stringstream ss;
            ss << std::hex << a;
            ss >> addr;
            cout << addr << "\n";
            //cout << addr << "\n";




        }
    }
    break;
    case 2: //fully
    {
        long long cache[blocks];
        index=0;
        tag=32-index-offset;
        while (1)
        {
            if (!getline(in,a))
            {
                break;
            }
            long long addr;
            std::stringstream ss;
            ss << std::hex << a;
            ss >> addr;
            cout << addr << "\n";
            //cout << addr << "\n";




        }
    }
    break;
    }




    while (1)
    {
        if (!getline(in,a))
        {
            break;
        }
        long long addr;
        std::stringstream ss;
        ss << std::hex << a;
        ss >> addr;
        cout << addr << "\n";
        //cout << addr << "\n";




    }

    return 0;
}

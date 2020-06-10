
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //read file name
    fstream in;
    fstream out;

    in.open("trace1.txt",ios::in);
    out.open("trace1out.txt",ios::out);
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
    //cout << policy;

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
        for(int i=0; i<blocks; i++)
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
            /////////////////////////////////////////////
            //convert hex tag and index into dec format//
            /////////////////////////////////////////////



            ///////////////////////////////////////
            ////have error while finding index bits
            ///////////////////////////////////////
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
            /////////
            //cache//
            /////////
            int num=indexs%blocks;
            if(cache[num]==-1||cache[num]==tags)
            {
                cout << -1 << endl;
                cache[num]=tags;
            }
            else
            {
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
        long long cache[4][asd];
        index=log2(asd);//bits of index
        tag=32-index-offset;
        for(int i=0; i<4; i++)
            for(int j=0; j<asd; j++)
                cache[i][j]=-1;
        int cnt=0;
        while (1)
        {
            if (!getline(in,a))
            {
                break;
            }
            long long addr;
            int tags;
            int indexs;
            /////////////////////////////////////////////
            //convert hex tag and index into dec format//
            /////////////////////////////////////////////

            ///////////////////////////////////////
            ////have error while finding index bits
            ///////////////////////////////////////
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
            /////////
            //cache//
            /////////
            addr=indexs%4;
            int flag=0;
            cout << index << endl;
            //cout << addr << endl;
            for(int i=0; i<asd; i++)
                if(cache[addr][i]==-1||cache[addr][i]==tags) //cache hit or cache isnot full
                {
                    cout << -1 << endl;
                    cache[addr][i]=tags;
                    flag=1;
                    break;
                }
            if(!flag){//cache miss and cache is full
                switch(algo){
                    case 0:{//FIFO
                        cout << cache[addr][cnt] << endl;
                        cache[addr][cnt]=tags;
                        cnt++;
                        cnt%=asd;
                        break;
                    }
                    case 1:{//LRU

                        break;
                    }
                    case 2:{//my algo

                        break;
                    }

                }
            }


        }

    }
    break;
    case 2: //fully
    {
        long long cache[blocks];
        long long tim[blocks];
        int t=0;
        index=0;
        tag=32-index-offset;
        for(int i=0; i<blocks; i++)
            cache[i]=0;
        int cnt=0;
        while (1)
        {
            if (!getline(in,a))
            {
                break;
            }
            long long addr;
            int tags;
            int indexs;
            /////////////////////////////////////////////
            //convert hex tag and index into dec format//
            /////////////////////////////////////////////
            std::stringstream ss;
            std::stringstream gg;
            /*
            ss << std::hex << a;
            ss >> addr;
            */
            string temp=a.substr(2,tag/4);
            tmp=2+tag/4;

            //string ind=a.substr(tmp,index/4);

            ss<< std:: hex << temp;
            ss>> tags;

            //gg<< std:: hex << ind;
            //gg>> indexs;
            /////////
            //cache//
            /////////
            //cache hit >> flag=1


            int flag=0;
            for(int i=0; i<cnt; i++)
                if(cache[i]==tags)
                {
                    flag=1;
                    tim[i]=t;
                    t++;
                    cout << -1 << endl;
                    break;
                }
            //cache miss,write into cache
            if(flag);
            else if(cnt<blocks) //cache isnot full
            {
                cache[cnt]=tags;
                tim[cnt]=t;
                t++;
                cnt++;
                cout << -1 << endl;
            }
            else //cache is full
            {
                switch(algo)
                {
                case (0): //FIFO
                {
                    cnt%=blocks;
                    cout << cache[cnt]<<endl;
                    cache[cnt]=tags;
                    cnt++;
                    break;
                }
                case (1): //LRU
                {
                    int m=1e9;
                    int n;//least reference number
                    for(int i=0; i<blocks; i++) //find the least reference block
                    {
                        if(tim[i]<m)
                        {
                            m=tim[i];
                            n=i;
                        }
                        cout << cache[n] << endl;
                        cache[n]=tags;
                        tim[n]=t;
                        t++;
                    }
                    break;
                }
                case (2): //my algo
                {

                    break;
                }
                }
            }



        }
    }
    break;
    }



    /*
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
    */
    return 0;
}

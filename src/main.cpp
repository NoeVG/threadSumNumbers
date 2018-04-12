#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;



vector<int> initialRank;
vector<int> endRank;

void appointRank(int,unsigned long int);

void *myThreadFun(void *vargp)
{
    sleep(1);
    // Store the value argument passed to this thread

    printf("Thread  \n");
    return NULL;
}

int main(){
  unsigned long int numberSum = 1000;
  unsigned long int totalSum = 0;
  unsigned long int limitNumberThreads = 4;
  unsigned long int numberThreads = 0;
  int iterThread = 0;
  int iterLimitThread = 0;
  pthread_t tid[numberThreads];


  for(iterLimitThread = 1; iterLimitThread < limitNumberThreads; iterLimitThread++ )
  {
    numberThreads = iterLimitThread;
    cout<<"Number Threads : "<<numberThreads<<endl;
    appointRank(numberThreads,numberSum);
    sleep(1);
    for(iterThread = 0; iterThread < numberThreads;iterThread++){
    pthread_create(&tid[iterThread], NULL, myThreadFun,NULL);

    }
    for(iterThread = 0; iterThread < numberThreads;iterThread++){
    pthread_join(tid[iterThread], NULL);
    }
  }

  return 0;
}

void appointRank(int numberThreads,unsigned long int numberSum){
  int sizeOfRank = 0;
  int iterRank = 0;

  sizeOfRank = numberSum / numberThreads;

  for(iterRank = 0;iterRank < numberThreads; iterRank++){
    initialRank.push_back( (slsizeOfRank*iterRank)+1);
    endRank.push_back( (sizeOfRank*(iterRank+1)));
    cout<<"\tInitial Rank: "<<initialRank.at(iterRank)<<endl;
    cout<<"\tEnd Rank: "<<endRank.at(iterRank)<<endl;
  }

}

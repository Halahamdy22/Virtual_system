
#define MAX_SIZE 5000
struct PCB *Object;
struct ProcessPCB
{

    int arrivaltime;
    int priority;
    int runningtime;
    int remanningtime;
    int id;
    int pid;
    char state[10];

};
struct PCB
{
   struct ProcessPCB Procsess[MAX_SIZE];
   int count;

   
};
// where should i decaler it???

 // Object.count=0;
void Push(struct ProcessPCB p)
{
   
   
   Object->Procsess[Object->count++]=p;
}
void POP(struct ProcessPCB p)
{
    Object->Procsess[Object->count].arrivaltime=-1;
    Object->Procsess[Object->count].priority=-1;
    Object->Procsess[Object->count].runningtime=-1;
    Object->Procsess[Object->count].remanningtime=-1;
    Object->Procsess[Object->count].id=-1;
    Object->Procsess[Object->count].pid=-1;
    // Object.Procsess[Object.count].state[0]='      ';
    Object->count--;

}
void Remove(struct ProcessPCB p)
{
    for(int i=0;i<Object->count;i++)
    {
        Object->Procsess[i]=Object->Procsess[i+1];
    }
    Object->Procsess[Object->count-1].arrivaltime=-1;
    Object->Procsess[Object->count-1].priority=-1;
    Object->Procsess[Object->count-1].runningtime=-1;
    Object->Procsess[Object->count-1].remanningtime=-1;
    Object->Procsess[Object->count-1].id=-1;
    Object->Procsess[Object->count-1].pid=-1;
    Object->count--;

}
void Insert(struct ProcessPCB p)
{
    Object->count ++;
     for(int i=0;i<Object->count;i++ )
     {
         Object->Procsess[i+1]=Object->Procsess[i];
     }
     Object->Procsess[0]=p;
}
void Clear(struct ProcessPCB p)
{

for(int i=0;i<Object->count;i++)
    {
        Object->Procsess[i].arrivaltime=-1;
    Object->Procsess[i].priority=-1;
    Object->Procsess[i].runningtime=-1;
    Object->Procsess[i].remanningtime=-1;
    Object->Procsess[i].id=-1;
    Object->Procsess[i].pid=-1;

    }
     Object->count=0;

}
int getProcess(int pid)
{
     for(int i=0;i<Object->count;i++)
     {
         if(Object->Procsess[i].pid==pid)
         {
             return i;

         }
     }
     return -1;
}
void Swap(int i,int j)
{
   struct ProcessPCB P=Object->Procsess[i];
   Object->Procsess[i]=Object->Procsess[j];
   Object->Procsess[j]=P;

}
void sortrunnigtime()
{
    
   
    for(int i=0;i<Object->count;i++)
    {
        int index=i;
          for(int j=i+1;j<Object->count;j++)
          {
                   if(Object->Procsess[index].runningtime>Object->Procsess[j].runningtime)
                   {
                       index=j;
                   }
          }
          Swap(index,i);
    }
    
    
}



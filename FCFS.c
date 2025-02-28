#include<stdio.h>
#include<stdlib.h>


struct fcfs{
  int pno; //assigning unique pno
  int AT; //assigning arrival time for each processes 
  int BT; //assigning burst time for each processes
  int CT; //calculating completition time for processes
  int TAT; //calculating turnaround time for processes
  int WT; //calculating waiting time for each processes
};

void sort(struct fcfs arr[],int n){
    struct fcfs temp;
    for(int i = 0;i < n; i++){
        for(int j = i+1;j < n; j++){
            if(arr[i].AT > arr[j].AT){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main(){
    int temp = 0;
    int atat = 0;
    int awt = 0;
    int n;

    
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);  //taking input for proccess numbers
    
    struct fcfs arr[n];
    //input for arrival and burst time and assigning process numbers to them
    for (int i = 0; i < n; i++) {
        arr[i].pno = i + 1; 
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arr[i].AT);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &arr[i].BT);
    }
    
    sort(arr,n); //ssorting based on arrival time
    
    for(int i = 0; i < n; i++){
        if(temp < arr[i].AT){
            printf("Idle Time of the CPU : %d -> %d",temp,arr[i].AT);
            temp = arr[i].AT;
            
        }
        arr[i].CT = temp + arr[i].BT; //completition time of the processes
        arr[i].TAT = arr[i].CT - arr[i].AT; // turnaround timw of the processes
        arr[i].WT = arr[i].TAT - arr[i].BT; //waiting time of the processes
        
        atat += arr[i].TAT; //avaerage turnaround time
        awt += arr[i].WT; //average waiting time
        
        temp = arr[i].CT; //updating temp for further idle scenarios
                
    }
    
    printf("\nProcess No\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",
               arr[i].pno, arr[i].AT, arr[i].BT, arr[i].CT, arr[i].TAT, arr[i].WT);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)atat / n);
    printf("Average Waiting Time: %.2f\n", (float)awt / n);
    
}
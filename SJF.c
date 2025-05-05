#include<stdio.h>
#include<stdlib.h>


struct sjf{
  int pno; //assigning unique pno
  int AT; //assigning arrival time for each processes 
  int BT; //assigning burst time for each processes
  int CT; //calculating completition time for processes
  int TAT; //calculating turnaround time for processes
  int WT; //calculating waiting time for each processes
  int completed;
  
};

void sort(struct sjf arr[],int n){
    struct sjf temp;
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
    int completed = 0;
    
    
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);  //taking input for proccess numbers
    
    struct sjf arr[n];
    //input for arrival and burst time and assigning process numbers to them
    for (int i = 0; i < n; i++) {
        arr[i].pno = i + 1; 
        arr[i].completed = 0;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arr[i].AT);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &arr[i].BT);
    }
    
    sort(arr,n); //ssorting based on arrival time
    
    
    while(completed < n){
        int shortIndex = -1;
        int min_bt = 9999;
        
        for (int i = 0; i < n; i++){
            if(!arr[i].completed && arr[i].AT <= temp && arr[i].BT <= min_bt){
                shortIndex = i;
                min_bt = arr[i].BT;
            }
        }
        
        if(shortIndex == -1){
            printf("\nIdle Time till %d ",temp);
        }
        else{
            
        arr[shortIndex].CT = temp + arr[shortIndex].BT; //completition time of the processes
        arr[shortIndex].TAT = arr[shortIndex].CT - arr[shortIndex].AT; // turnaround timw of the processes
        arr[shortIndex].WT = arr[shortIndex].TAT - arr[shortIndex].BT; //waiting time of the processes
        
        atat += arr[shortIndex].TAT; //avaerage turnaround time
        awt += arr[shortIndex].WT; //average waiting time
        arr[shortIndex].completed = 1;
        
        temp = arr[shortIndex].CT; //updating temp for further idle scenarios
        completed++;
        }
    }
                
    
    
    printf("\nProcess No\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",
               arr[i].pno, arr[i].AT, arr[i].BT, arr[i].CT, arr[i].TAT, arr[i].WT);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)atat / n);
    printf("Average Waiting Time: %.2f\n", (float)awt / n);
    
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main(){

	int et[20],arrt[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10],et_copy[10];
    int totwt=0,totta=0;
    float avgwaitt,avgturna;
    char pn[10][10],t[10];

    printf("\nEnter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter process name:");
        //flushall();
        scanf("%s",pn[i]);
        printf("Enter arrival time: ");
        scanf("%d",&arrt[i]);
        printf("Enter execution time: ");
        scanf("%d",&et[i]);
        et_copy[i] = et[i];
    }


    int current_time = -1;
    int curr_job = -1;
    int jobs_complete = 0;
    int min_remaining_burst = 999999;
    int is_sort = 0;
    int nnn;
    int num_error_free_process = n;

    while(jobs_complete!=1){
    	jobs_complete = 1;
    	for(i=0;i<n;i++){
    		//printf("Arrt = %d\n",arrt[i] );
    		
    		if(arrt[i] > 0){
    			if(arrt[i] <= current_time){
    				if(et[i] > 0 && et[i] < min_remaining_burst){
    					curr_job = i;
    					is_sort = 1;
    				}	
    			}
    			if(et[i]>0)
    				jobs_complete = 0;
    		}
    	}
    	//printf("current_time = %d\n", current_time);
    	if(is_sort==1){
    		current_time+=2;
    		//printf("current_time + sort time = %d\n", current_time);
    	}
    	//printf("current_job = %d\n", curr_job);
    	if(curr_job == -1){
    		current_time++;
    		continue;
    	}
    	if(current_time == -1)
    		current_time = arrt[curr_job];
    	
    	st[curr_job] = current_time;
    	current_time += et[curr_job];
    	et[curr_job]=0;
    	ta[curr_job] = current_time - arrt[curr_job];
    	wt[curr_job] = ta[curr_job] - et_copy[curr_job];
    	//printf("Job executed, time = %d\n", current_time);
    	//scanf("%d", &nnn);
    	curr_job = -1;
    }


    for(i=0;i<n;i++){
    	if(arrt[i]<=0){
    		ta[i] = 0;
    		wt[i] = 0;
    		num_error_free_process--;
    	}
    	totta += ta[i];
    	totwt += wt[i];
    }

    
    avgwaitt=(float)totwt/num_error_free_process;
    avgturna=(float)totta/num_error_free_process;

    printf("\nPname\tarr_time\texe_time\twt_time\t\t ta_time");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],arrt[i],et_copy[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f\n",avgwaitt);
    printf("\nAverage turnaroundtime is:%f\n",avgturna);


	return 0;
}

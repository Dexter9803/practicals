#include<iostream>
using namespace std;

class Patient
{
    public:
    string name;
    int priority;
    Patient* next;

    Patient(const string &n, int p)
    {
        name = n;
        priority = p;
        next = NULL;
    }
};

class Hospital
{
    private:
    Patient* front;

    public:
    Hospital()
    {
        front = NULL;
    }

    void addPatient(const string& name, int priority)
    {
        Patient* newPatient = new Patient(name, priority);
        
        if(front == NULL || priority < front->priority)
        {
            newPatient->next = front;
            front = newPatient;
        }
        else
        {
            Patient* current = front;
            
            while((current->next != NULL) && (current->next->priority <= priority))
            {
                current = current->next;
            }

            newPatient->next = current->next;
            current->next = newPatient;
        }
    }

    void process()
    {
        Patient* current = front;
        while(current != NULL)
        {
            cout<<"Processing Patient "<<current->name<<endl;
            current = current->next;
        }
    }
};

int main()
{
    Hospital hospital;
	int n;
	cout<<"Enter number of patients: ";
	cin>>n;

	for(int i=0; i<n; i++)
	{
		string name;
		int prio;
		cout<<"\nEnter name of the patient: ";
		cin>>name;
		cout<<"Enter priority - Serious(1)/ Non-serious(2)/ General checkup(3) : ";
		cin>>prio;
		cout<<endl;
		hospital.addPatient(name, prio);
	}
	
	cout<<endl<<"Processing patients: "<<endl;
    hospital.process();
    return 0;
}
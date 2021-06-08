class Counter{
private:
	int count;
	int step_val;
public:
	Counter():count(0),step_val(1){}
	void setIncrementStep(int step_val){this->step_val	= step_val;}
	int getCount(){return count;}
	void increment(){count += step_val;}
	void resetCount(){count=0;}
};
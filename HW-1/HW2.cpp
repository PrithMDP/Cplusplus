#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>      // std::setprecision

using namespace std;
//global plaintext
string plaintext = "ethicslawanduniversitypolicieswarningtodefendasystemyouneedtobeabletothinklikeanattackerandthatincludesunderstandingtechniquesthatcanbeusedtocompromisesecurityhoweverusingthosetechniquesintherealworldmayviolatethelawortheuniversitysrulesanditmaybeunethicalundersomecircumstancesevenprobingforweaknessesmayresultinseverepenaltiesuptoandincludingexpulsioncivilfinesandjailtimeourpolicyineecsisthatyoumustrespecttheprivacyandpropertyrightsofothersatalltimesorelseyouwillfailthecourseactinglawfullyandethicallyisyourresponsibilitycarefullyreadthecomputerfraudandabuseactcfaaafederalstatutethatbroadlycriminalizescomputerintrusionthisisoneofseverallawsthatgovernhackingunderstandwhatthelawprohibitsifindoubtwecanreferyoutoanattorneypleasereviewitsspoliciesonresponsibleuseoftechnologyresourcesandcaenspolicydocumentsforguidelinesconcerningproper";
vector<string> vec;
void cipher(string key);
void calcvar();
void varfromvec();
void var_part_e();
string key;
bool part_e=false;
map<char,double> char_count;
int main(int argc,  char** argv)

{
	cout<<"Enter Key:";
	cin >>key;
	
	if(argv[1])
	{
		cout<<"here\n";
		part_e=true;
		key="uvwxyz";
		cipher(key);
		var_part_e();
		exit(1);
	}
	else
	{
		cipher(key);
	}
	calcvar();
	varfromvec();
	
}

//finds cipher here
void cipher(string key)
{
	for(unsigned i=0;i<plaintext.length();i++)
	{	//go over the entire string
		int to_add=i%key.length();
		plaintext[i]-=97;
		plaintext[i]+=(key[to_add]-97);
		plaintext[i]=plaintext[i]%26;
		plaintext[i]+=97;
	}
}


void calcvar()
{
	map<char,double> char_count;
	for(unsigned i=0;i<plaintext.length();i++)	//set to 0
	{
		char_count[plaintext[i]]=0;
	}
	for(unsigned i=0;i<plaintext.length();i++)	//increment counter
	{
		char_count[plaintext[i]]+=1;
	}
	double totalchars=plaintext.length();	//total length
	
	map<char, double>::iterator iter;	//iterator
	for (iter = char_count.begin(); iter != char_count.end(); ++iter)
	{
		iter->second/=totalchars;	//finding the percentage
	}
	//calculate mean
	double mean=0;
	for (iter = char_count.begin(); iter != char_count.end(); ++iter)
	{
		mean+=iter->second;
	}
	mean/=26;

	//reset iter
	iter=char_count.begin();
	//set pop_var =0
	double pop_var=0;
	for (iter = char_count.begin(); iter != char_count.end(); ++iter)
	{
		pop_var+=(iter->second-mean)*(iter->second-mean);
	}

	pop_var/=26; //num chars

	cout<<"POP VAR IN CYPHERED IS: "<<setprecision(12)<<pop_var<<endl;

//part d -> 2 cyphers variance then mean , then 3 y-> in 1 string z-> in 1 string y variance and z variance
	if(key.length()==2)
	{
		vec.resize(2);

	for(unsigned i=0; i<plaintext.length();i++)
		{
			vec[i%(key.length())]+=plaintext[i];
		}
	}
	if(key.length()==3)
	{
		vec.resize(3);
		for(unsigned i=0; i<plaintext.length();i++)
		{
			vec[i%(key.length())]+=plaintext[i];
		}

	}
	if(key.length()==4)
	{
		vec.resize(4);
		for(unsigned i=0; i<plaintext.length();i++)
		{
			vec[i%(key.length())]+=plaintext[i];
		}

	}
	if(key.length()==5)
	{
		vec.resize(5);
		for(unsigned i=0; i<plaintext.length();i++)
		{
			vec[i%(key.length())]+=plaintext[i];
		}

	}
	if(key.length()==6)
	{
		vec.resize(6);
		for(unsigned i=0; i<plaintext.length();i++)
		{
			vec[i%(key.length())]+=plaintext[i];
		}

	}
	

}
void varfromvec()
{
	vector<double> final;
	for(int i=0;i<vec.size();i++)
	{
		map<char,double> c_counter;
		string str=vec[i];
		for(unsigned j=0;j<str.size();j++)
		{
			char the= str[j];
			c_counter[the]+=1;	//map set 
		}
		//now calc variance here
		map<char, double>::iterator iter;
		for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
		{
			iter->second/=vec[i].size();	//finding the percentage
		}
		double mean=0;
		for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
		{
			mean+=iter->second;
		}
		mean/=26;
		//mean here
		double pop_var=0;
		for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
		{
			pop_var+=(iter->second-mean)*(iter->second-mean);
		}
		pop_var/=26; //num chars
		final.push_back(pop_var);
	}
	double d_ans;
	for(int i=0;i<final.size();i++)
	{
		d_ans+=final[i];
	}
	d_ans/=final.size();
	cout<<"mean var "<<setprecision(12)<<d_ans<<endl;
}
void var_part_e()
{
	for(int i=2;i<6;i++)	//diff key lengths
	{
		vector<double> final;

		vector<string> for_e;
		for_e.resize(i);
		
		for(unsigned j=0; j<plaintext.length();j++)
		{
			for_e[j%i]+=plaintext[j];	//writing to vector
		}
		
		for(int a=0;a<for_e.size();a++)	//for 1 string in vector
		{
			map<char,double> c_counter;
			string str=for_e[a];
			for(unsigned b=0;b<str.size();b++)
			{
				char the= str[b];
				c_counter[the]+=1;	//map set 
			}
		//now calc variance here
			//cout<<for_e[a].size()<<endl;
			map<char, double>::iterator iter;
			for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
			{
				iter->second/=for_e[a].size();	//finding the percentage
			}
			double mean=0;
			for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
			{
				mean+=iter->second;
			}
			mean/=26;
			//mean here
			double pop_var=0;
			for (iter = c_counter.begin(); iter != c_counter.end(); ++iter)
			{
				pop_var+=(iter->second-mean)*(iter->second-mean);
			}
			pop_var/=26; //num chars
			final.push_back(pop_var);
		}
		double d_ans=0;
		for(int cd=0;cd<final.size();cd++)
		{
			d_ans+=final[cd];
		}
		d_ans/=final.size();
		cout<<" length in this case is "<<i<<" "<<d_ans<<endl;

	}
}


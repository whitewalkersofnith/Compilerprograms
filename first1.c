#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter Number of Productions: ";
	cin>>n;

	vector <string> rhs;
	vector <char> sk;
	string productions[n];

	for(int i=0;i<n;i++){

		cin>>productions[i];
		for(int j=3;j<productions[i].size();j++){

			string temp="";
			while(productions[i][j]!='|' && j<productions[i].size()){

				temp+=productions[i][j];
				j++;
			}
			
			if(temp.size()>0){

				rhs.push_back(temp);
				sk.push_back(productions[i][0]);
			}
		}
	}


	cout<<"Enter any Input String: ";
	string s;
	cin>>s;
	string check="";
	string k1 = s;

	cout<<endl<<check<<"$\t"<<s<<"$\tShift\n";
	for(int i=0;i<s.size();i++){

		int f=0;
		check+=s[i];
		k1.erase(k1.begin());

		for(int j=0;j<rhs.size();j++){

			if(check.find(rhs[j])<check.size()){

				f++;

				cout<<"$"<<check<<"\t"<<k1<<"$\t\tReduce\n";

				int temp=rhs[j].size();
				while(temp--) check.erase(check.end()-1);

				check+=sk[j];				
				j=-1;
			}
		}

		if(!k1.empty()) cout<<"$"<<check<<"\t"<<k1<<"$\t\tShift\n";
	}
	cout<<"$"<<check<<"\t"<<k1<<"$\n\n";


	if(check=="S" && k1.size()==0) cout<<"Accepted"<<endl;
	else cout<<"Rejected"<<endl;
}

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template <class T>
class Queue;


template <class T>
Queue<T> operator +(const Queue<T> &s1, const Queue<T> &s2){
    Queue<T> result = s1;

    for(unsigned i = 0; i < s1.cola.size();i++) {
        result.cola.push_front (s2.cola [i]);
    }
    return result;
}

template <typename T>
Queue<T> operator -(const Queue <T> &s1, const Queue<T> &s2)
{
    Queue<T> result;
    for(unsigned i=0; i<s1.cola.size();i++)
    {
        bool temp=false;
        for(unsigned j=0; j<s2.cola.size();j++)
        {
            if(s1.cola[i]==s2.cola[j])
                temp=true;
        }
        if(temp==false)
            result.push(s1.cola[i]);
    }
    return result;
}
/*
template <class T>

Queue<T> operator -(const Queue<T> &s1, const Queue<T> &s2) {
	Queue<T> result;
	deque<int> c1;
	for (unsigned i = 0;i < s1.cola.size();i++) {
		bool repite = true;
		for (unsigned j = 0;j < s2.cola.size();j++) {
			if (s1.cola[i] == s2.cola[j]) {
				c1.push_front(s1.cola[i]);
				repite = false;
				break;

			}

		}
		if (repite == true) {
			result.push(s1.cola[i]);
		}

	}
	for (unsigned i = 0;i < s2.cola.size();i++) {
		for(unsigned j=0;j<c1.size();j++){
			if (s2.cola[i] != c1[j]) {
				result.cola.push_back(s2.cola[i]);
			}
		}
	}
	return result;
}
*/
template <typename T>
class Queue{
    friend ostream &operator <<(ostream &s2,Queue &s1)
    {
       for(int i=s1.cola.size()-1;i >= 0; i--)
         s2<<s1.cola[i]<<endl;
       return s2;
    }
    friend Queue<T> operator +<>(const Queue<T> &s1, const Queue<T> &s2);
    friend Queue<T> operator -<>(const Queue <T> &s1, const Queue<T> &s2);

    deque <T> cola;
    public:

        T push(const T &item) {cola.push_front(item);}
        T pop(){
            //T ultimo = cola.front();
            cola.pop_back();
            //return ultimo;
        }
};

int main()
{
    Queue<int> a,b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Queue<int> c = a+b;
    Queue<int> d = c-a;
    //a.pop();
    //b.pop();
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
}

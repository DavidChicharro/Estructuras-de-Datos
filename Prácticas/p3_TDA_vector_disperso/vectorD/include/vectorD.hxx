#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

template <class T>
int vectorD<T>::checkRepFails(){
	int fallo = 0;
	
	if (0 > vd.size() || vd.size() >= n_ele)
		fallo = 1;


	bool fallo_2 = true;
	vectorD<T>::stored_iterator s_it;
  for (int i=0 ; i<vd.size() && fallo_2 ; ++i)
  	if (vd[i].second != v_nulo)
  		bool fallo_2 = false;
  
  if (fallo_2)
  	fallo = 2;

  for (int i=0 ; i<vd.size() && fallo == 0 ; ++i)
  	if (vd[i].first < 0)
  		fallo = 3;

  for (int i=0 ; i<vd.size() && fallo == 0 ; ++i){
  	if (vd[i].first >= i+1)
  		fallo = 4;
  }

  return fallo;
}

template <class T>
void vectorD<T>::copy(const vectorD<T> & x){
	n_ele = x.n_ele;
  v_nulo = x.t;
  
  vectorD<T>::stored_iterator s_it;
  for (s_it=x.sbegin() ; s_it!=x.send() ; ++s_it)
  	vd.push_back(make_pair((*s_it).first,(*s_it).second));
}

template <class T>
bool vectorD<T>::equals( const vectorD<T> & x){
	bool eq = true;;
	vectorD<T>::stored_iterator s_it;
	vectorD<T>::stored_iterator other_s_it = x.sbegin();
	for (s_it = sbegin() ; s_it != send() && eq ; ++s_it){
		if(!((*s_it).first == (*other_s_it).first 
			&& (*s_it).second == (*other_s_it).second))
			eq = false;
			other_s_it++;
	}
	return eq;
}


template <class T>
vectorD<T>::vectorD(const  T  & t){
  n_ele = 0;                  
  v_nulo = t;
}

template <class T>
vectorD<T>::vectorD(const vectorD<T> & b){
  copy(b);
}

template <class T>
vectorD<T>::vectorD(int numcomp, const  T  & t){
	if (numcomp >= 0){
		n_ele = numcomp;
		v_nulo = t;
	}
}

template <class T>
vectorD<T>::~vectorD(){}


template <class T>
typename vectorD<T>::size_type vectorD<T>::size() const{
  return n_ele;
}


template <class T>
T vectorD<T>::default_value() const{
	return v_nulo;
}


template <class T>
bool vectorD<T>::empty(){
	return n_ele == 0;
}


template <class T>
void vectorD<T>::set(int p, const T & t){
	if(p >= 0 && (unsigned)p<n_ele){
		bool existe = false;
		bool continuar = true;
		typename list<pair<int,T> >::iterator it;

		for (it = vd.begin() ; it!=vd.end() && (!existe || continuar) ; ++it){
	  	if ((*it).first == p)
	  		existe = true;
	  	if (p > (*it).first )
		  	continuar = false;
	  }

	  pair<int, T> nuevo (p, t);
		if(existe){
			if(t != v_nulo)
				vd.insert(it, nuevo);
			else
				it = vd.erase(it);
		}
		else
			vd.insert(it, nuevo);
	}
}

template <class T>
void vectorD<T>::push_back( const  T  & t){
	if(t != v_nulo)
		vd.push_back(make_pair(n_ele,t));
	n_ele++;
}

template <class T>
void vectorD<T>::pop_back(  ){
	if (vd.back().second != v_nulo)
		vd.pop_back();
	n_ele--;
}

template <class T>
void vectorD<T>::clear(){
	vd.clear();
	n_ele = 0;
}

template <class T>
void vectorD<T>::resize(int s){
	if ((unsigned)s<n_ele)
		while(vd.back().first >= s)
			vd.pop_back();
	n_ele = s;
}

template <class T>
vectorD<T> & vectorD<T>::operator= (const vectorD<T> & x){
	copy(x);

	return this;
}

template <class T>
const  T  & vectorD<T>::operator[](unsigned c) const{
	assert (c >= 0 && c<n_ele);
	bool found = false;
	vectorD<T>::stored_iterator s_it;

	for (s_it = sbegin() ; s_it!=send() && !found ; ++s_it)
		if((int)c==(*s_it).first)
			found = true;
		
	s_it--;
	if (found)
		return (*s_it).second;
	else
		return v_nulo;
}

template <class T>
bool vectorD<T>::operator==( const vectorD<T> & x){
	return equals(x);
}

template <class T>
bool vectorD<T>::operator!=( const vectorD<T> & x){
	return !(equals(x));
}

template <class T>
typename vectorD<T>::iterator vectorD<T>::begin(){
	iterator it;
	it.ite_rep = vd.begin();
	it.el_vect = this;

	return it;
}

template <class T>
typename vectorD<T>::iterator vectorD<T>::end(){
	iterator it;
	it.ite_rep = vd.end();
	it.i_vect = n_ele;
	it.el_vect = this;
	
	return it;
}

template <class T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin() const{
	stored_iterator si;
	si.ite = vd.begin();

	return si;
}

template <class T>
typename vectorD<T>::stored_iterator vectorD<T>::send() const{
	stored_iterator si;
	si.ite = vd.end();

	return si;
}



template <class T>
vectorD<T>::stored_iterator::stored_iterator() {}

template <class T>
vectorD<T>::stored_iterator::stored_iterator(const stored_iterator & d) : ite(d.ite) {}

template <class T>
const pair<int, T > & vectorD<T>::stored_iterator::operator *( ){
	return (*ite);
}

template <class T>
typename vectorD<T>::stored_iterator & vectorD<T>::stored_iterator::operator++( ){
	++ite;
	return *this;
}

template <class T>
typename vectorD<T>::stored_iterator & vectorD<T>::stored_iterator::operator--( ){
	--ite;
	return *this;
}

template <class T>
bool vectorD<T>::stored_iterator::operator == (const stored_iterator & d){
	return ite == d.ite;
}

template <class T>
bool vectorD<T>::stored_iterator::operator != (const stored_iterator & d){
	return ite != d.ite;
}



template <class T>
vectorD<T>::iterator::iterator() :i_vect(0) {}

template <class T>
vectorD<T>::iterator::iterator(const iterator & d){
	copy_it(d);
}

template <class T>
const  T  & vectorD<T>::iterator::operator *( ){
  if (i_vect == (*ite_rep).first)
    return (*ite_rep).second;
  else
    return el_vect->v_nulo;
}

template <class T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator++( ){
	if( i_vect == (*ite_rep).first)
	  ++ite_rep;

	i_vect++;
	return *this;
}

template <class T>
bool vectorD<T>::iterator::operator == (const iterator & d){
	return (i_vect == d.i_vect) && (ite_rep == d.ite_rep) && (el_vect == d.el_vect);
}

template <class T>
bool vectorD<T>::iterator::operator != (const iterator & d){
	return !((i_vect == d.i_vect) && (ite_rep == d.ite_rep) && (el_vect == d.el_vect));
}

template <class T>
typename vectorD<T>::iterator::iterator & vectorD<T>::iterator::operator=(const iterator & d){
  copy_it(d);
  return *this;
}

template <class T>
void vectorD<T>::iterator::copy_it(const iterator & d){
  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
} 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

	class file{
		private:
			file* 	view;
			char* 	name;
			char* 	content;
			int 	size;
			time_t date;
			file*	prevname;
			file*	nextname;
			file*	prevsize;
			file*	nextsize;
			file*	prevdate;
			file*	nextdate;
		public:
			file(){
				date=0;
			}
			void asign(){
				*view=*this;
			}
			void new_file(const char* _name_){
				time_t _date_=time(NULL);
				int _size_=0;
				char* _content_=NULL;
				file* aux=(file*)calloc(1,sizeof(file));
				aux->view=aux;
				aux->date=_date_;
				aux->name=(char*)malloc(sizeof(char)*strlen(_name_));
				strcpy(aux->name,_name_);
				char* tmp= new char[1000];
				while(gets(tmp)!=NULL){
					int prevsize=_size_;
					strcat(tmp,"\n");
					_size_+=strlen(tmp);
					_content_=(char*)realloc(_content_,_size_*sizeof(char));
					_content_[prevsize]='\0';
					strcat(_content_,tmp);
				}
				delete tmp;
				aux->size=_size_;
				aux->content=_content_;
				if(date==0){
					*this=*aux;
					asign();
				}else{
					file* it;
					it=view;
					it=point(0);
					while(true){
						if(it->nextname!=NULL){
							int tmp=strcmp(aux->name,it->name);
							if(tmp==0){
									//Nombre repetido
							}else{
								if(tmp<0){
										aux->prevname=it->prevname;
										aux->nextname=it;
										it->prevname=aux;
										break;
								}
								it=it->nextname;
							}
						}else{
							it->nextname=aux;
							aux->prevname=it;
							break;
						}
					}
					it=point(1);
					while(true){
						if(it->nextsize!=NULL){
							if(aux->size < it->size){
								aux->prevsize=it->prevsize;
								aux->nextsize=it;
								it->prevsize=aux;
								break;
							}
							it=it->nextsize;
						}else{
							it->nextsize=aux;
							aux->prevsize=it;
							break;
						}
					}
					it=point(2);
					while(true){
						if(it->nextdate!=NULL){
							if(aux->date < it->date){
								aux->prevdate=it->prevdate;
								aux->nextdate=it;
								it->prevdate=aux;
								break;
							}
							it=it->nextdate;
						}else{
							it->nextdate=aux;
							aux->prevdate=it;
							break;
						}
					}
				*this=*it;
				}
			}
			void rename(){
				
			}
			void remove(){
				
			}
			file* point(int opt){
				file* it=view;
				if(opt==0){
					while(it->prevname!=NULL){
						it=it->prevname;
					}
				}else if(opt==1){
					while(it->prevsize!=NULL){
						it=it->prevsize;
					}
				}else{
					while(it->prevdate!=NULL){
						it=it->prevdate;
					}
				}
				*this=*it;
				return it;
			}
			void modify(){
				
			}
			void edit(){
				
			}
			void add(){
				
			}
			void show_all(int opt){
				file* it;
				switch(opt){
					case 1:
						it=point(0);
						while(it!=NULL){
							printf("%s\t%d\t%s\n",it->name,it->size,asctime(localtime(&it->date)));
							it=it->nextname;
							}
						break;
					case 2:
						it=point(1);
						while(it!=NULL){
							printf("%s\t%d\t%s\n",it->name,it->size,asctime(localtime(&it->date)));
							it=it->nextsize;
						}
						break;
					case 3:
						it=point(2);
						while(it!=NULL){
							printf("%s\t%d\t%s\n",it->name,it->size,asctime(localtime(&it->date)));
							it=it->nextdate;
						}
						break;
				}
			}
			void var_dump(){
				puts("------------------------------------------------");
				cout<<"Nombre: "<<name<<endl;
				cout<<"Size: "<<size<<endl;
				cout<<"Fecha: "<<asctime(localtime(&date))<<endl;
				cout<<"Contenido: "<<endl;
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				puts(content);
				puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				
				puts("------------------------------------------------");
			}
	};
int main(){
	file f;
	f.new_file("alpha");
	f.new_file("beta");
	f.new_file("gamma");
	f.show_all(1);
	cout<<"--------\n";
	f.show_all(2);
	cout<<"--------\n";
	f.show_all(3);
	return 0;
}


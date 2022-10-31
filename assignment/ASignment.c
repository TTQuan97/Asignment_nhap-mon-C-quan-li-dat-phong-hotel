#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

/*
@Description:khai bao kieu liet ke tu dinh nghia
@prime : khoi tao ten bien kieu enum LIST*/
enum LIST{
	MENU=0,DATPHONG,HUYPHONG,INFOHOTEL,EXIT,TWOBED,THREEBED,XACNHAN	 //(int) 0-1-2-3-4-5-6-7
}prime;

/*
@Description:toa do cac dong tren man hinh console
@x,y: toa do truc tung-hoanh(ngang-doc)(cot-hang)tren man hinh console
@a : bien kieu toa do COORD dc dinh nghia san trong thu vien. 
@SetConsoleCursorPosition: setup con tro(o day la toa do) tren bang dieu khien(man hinh)
@GetStdHandle :truy xuat xu li toi 1 thiet bi Standard .ma o day dc chi dinh la STD_OUTPUT_HANDLE(xu li dau ra tieu chuan)*/
void toado(int x,int y){
	COORD a={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a); // ham setup con tro tren bang dieu khien(man hinh)
}
/*
@Description :setup color
@a:thong so mau sac (int)*/
void mausac(int a){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
/*
@Description:hien thi Menu chinh va con tro de chon chuc nang
@kbhit: ham kiem tra 1 phim da duoc an hay chua
@getch():tam dung man hanh console cho den khi 1 phim bat ki duoc bam*/
void display_menu(){
	mausac(125);
	system("cls");
	toado(47,1);
	printf("%c %s %c",4," WELCOME TO JAV HOTEL ",4,"\n");
	toado(53,2);
	printf("Vao La Thich");
	toado(55,4);
	printf("%c %s %c",3,"MENU",3,"\n");
	toado(45,5);
	printf("%c %s %c",4,"Moi quy khach chon dich vu ",4,"\n");
	toado(53,6);
	printf("1 :Dat phong.\n");
	toado(53,7);
	printf("2 :Huy Phong.\n");
	toado(53,8);
	printf("3 :Info Hotel.\n");
	toado(53,9);
	printf("4 :Exit.\n");
	toado(49,12);
	char arr[50];
	toado(49,11);
	mausac(126);	
	printf("%c %c %c %c %c %c %c %c %c %c %c %c",177,176,3,3,3,3,3,3,3,3,176,177);
	toado(50,6);
	printf("%c",16);			//toa do con tro ban dau( dong 1-Dat phong)
	int choice=1;				//khoi tao bien choice ,key
	int key;
	while(prime==MENU){			//vi ham main da gan co dinh prime=MENU(=0) nen while() se luon dung , lap vo tan
		if(kbhit()){
			key=getch();
			if(key==80){		//***neu key==80 (80: phim mui ten xuong tren ban phim)
				choice++;
				if(choice==5){
					choice=1;	//gan lai choice=1 de choice ko bi qua lon chay tu case 2-3-4
				}	
			}
			if(key==72){		//***neu an phim 72(phim mui ten di len tren ban phim)
				choice--;
				if(choice==0){
					choice=4;	//gan lai choice==4 de con tro hien thi o dong 4(exit) chay tu case 4-3-2-1
				}
			}
			switch(choice){			//ban dau choice se ==2
				case 1:				//khi ma lap xong 1 vong dau tien .choice==4 thì lai cho choice ==1. se thuc hien case 1		
					toado(50,7);
					printf(" ");
					toado(50,8);
					printf(" ");
					toado(50,9);
					printf(" ");
					toado(50,6);		
					printf("%c",16);	//in con tro vao dong 1(datphong)
					break;
				case 2:
					toado(50,6);		
					printf(" ");		// in  "khoang trang" vao doa do con tro ban dau(datphong)
					toado(50,8);	
					printf(" ");		// in "khoang trang" vao  dong 3(info)
					toado(50,9);
					printf(" ");		// in "khoang trang" vao  dong 4 (exit)
					toado(50,7);
					printf("%c",16);	// in con tro vao toa do dong 2 (huy phong)
					break;		
				case 3:
					toado(50,6);		
					printf(" ");		// in "khoang trang" vao toa do dong 1(datphong)
					toado(50,7);		
					printf(" ");		// in "khoang trang" vao toa do dong 2(huyphong)
					toado(50,9);
					printf(" ");		// in "khoang trang" vao toa do dong 4(exit)
					toado(50,8);	
					printf("%c",16);	// in con tro vao toa do dong 3(info)
					break;
				case 4:
					toado(50,6);		
					printf(" ");		//in "khoang trang" vao dong 1
					toado(50,7);	
					printf(" ");		// in "khoang trang" vao dong 2
					toado(50,8);	
					printf(" ");		// in "khoang trang" vao toa do dong 3
					toado(50,9);
					printf("%c",16);	// in con tro vao toa do dong 4(exit)	
					break;	
			}
			if(key==13){				//***neu an phim 13( enter) thi se chay switch()
				switch(choice){			
					case 1:
						prime=DATPHONG;		//choice o tren la 1 thi se chay case 1,va gan prime=2
						break;
					case 2:
						prime=HUYPHONG;		//choice o tren la 2 thi se chay case 2 gan prime =3
						break;
					case 3:
						prime=INFOHOTEL;			//choice o tren la 3 thi se chay case 3 gan prime =4
						break;	
					case 4:
						prime=EXIT;			//choice o tren la 4 thi se chay case 4	gan prime =5
						break;
				}
			}
		}
	}
}
char cccd[20],name[30];
/*
@Description : nhap so Can cuoc cong dan/Passport-ten khach hang tu ban phim vao mang cccd[] va name[]
@nhap thoi gian tra phong tu ban phim*/
void stdin_infomation(){
	system("cls");
	fflush(stdin);
	toado(50,1);
	printf("%c %s %c",3,"JAV HOTEL",3);
	toado(42,3);
	printf("%c %s",3,"Nhap so CCCD / Passport :");
	gets(cccd);	
	toado(42,4);									
	printf("%c %s",3,"Nhap Ten Khach Hang :");
	gets(name);	
}
/*
@Description:Khai bao bien toan cuc...tat cac se dùng chung bien nay.
luu gia tri thoi gian "Tra Phong" nhap tu ban phim*/
int hour_end;
int minute_end;
int day_end;
int month_end;
int year_end;
/*
@Description:nhap thoi gian Tra Phong tu ban phim*/
void stdin_time(){
	if(prime==DATPHONG){				//neu ham check_cccd_passport_input tra ve prime=MENU thi se ko thuc hien function nay
		toado(45,6);
		printf("Nhap gio tra phong :");
		toado(40,8);
		printf("%c %s",3," gio ");
		toado(35,8);
		scanf("%d",&hour_end);
		toado(55,8);
		printf("%c %s",3," phut ");
		toado(50,8);
		scanf("%d",&minute_end);
		toado(33,10);
		printf("%c %s",3,"nhap ngay: ");
		toado(45,10);
		scanf("%d",&day_end);
		toado(50,10);
		printf("%c %s",3,"nhap thang: ");
		toado(63,10);
		scanf("%d",&month_end);
		toado(69,10);
		printf("%c %s",3,"nhap nam: ");
		toado(80,10);
		scanf("%d",&year_end);	
	}
}
/*
@kiem tra cccd/passport nhap vao co bi trung vs trong he thong hay khong,neu co thi stop
@cccd :so cccd da nhap o tren . */
void check_cccd_passport_input(){
	int count=0;
	char room[2],passport[30],save_hour[2],save_min[2],save_day[2],save_month[2],save_year[4],info[40];
	FILE*ptrtwo=fopen("infotwobed.txt","r");	//doc file info 2 giuong
	FILE*ptrthree=fopen("infothreebed.txt","r");//doc file info 3 giuong	
	while(!feof(ptrtwo)){						//ham feof : kiem tra xem 1 file da het hay chua. 
		fscanf(ptrtwo,"%s",room);				//so phong.
		fscanf(ptrtwo,"%s",passport);			//fscanf :doc file theo dinh dang... doc den khoang trang se Stop.///doc tung dong trong file	
		fscanf(ptrtwo,"%s",save_hour);			//doc gio
		fscanf(ptrtwo,"%s",save_min);			//doc phut
		fscanf(ptrtwo,"%s",save_day);			//doc ngay
		fscanf(ptrtwo,"%s",save_month);			//doc thang	
		fscanf(ptrtwo,"%s",save_year);			//doc nam
		fgets(info,sizeof info,ptrtwo);			// fgets :se doc tiep phan con lai...Name
		if(strcmp(cccd,passport)==0){			//strcmp: so sanh 2 chuoi. so sanh CCCD nhap tu ban phim VS CCCD doc tu file (luu trong passport[])	
			toado(32,10);
			printf("%c %s %c",4,"Can cuoc cong dan / Passport da ton tai. Vui long kiem tra lai",4);
			toado(25,16);
			printf("%c %s %s",3,"So phong :",room);		
			toado(25,17);
			printf("%c %s %s",3,"Can cuoc cong dan/ Passport : ",passport); 			
			toado(25,18);
			printf("%c %s %s",3,"Name : ",info);//in name
			toado(25,19);
			printf("%c %s",3,"Ngay/gio dat phong :");
			toado(47,19);
			printf("%s %s",save_hour,"gio");	//in gio dat phong
			toado(55,19);
			printf("%s %s",save_min,"phut");	//in phut dat phong
			toado(65,19);
			printf("%s %s","Ngay ",save_day);	//in ngay dat phong
			toado(75,19);
			printf("%s %s","Thang ",save_month);//in thang dat phong
			toado(85,19);
			printf("%s %s","Nam ",save_year);	//in nam dat phong	
			count++;							//neu tim that gia tri trung nhau thi count ++
			prime=MENU;
			getch();
			break;
			
		}
	}
	if(count==0){										//neu o tren ko tim thay gia tri trung nhau thi se doc file 3phong. thuc hien vong lap nay	
		while(!feof(ptrthree)){							//ham feof : kiem tra xem 1 file da het hay chua. 
			fscanf(ptrthree,"%s",room);
			fscanf(ptrthree,"%s",passport);				//fscanf :doc file theo dinh dang... doc den khoang trang se Stop.///doc tung dong trong file	
			fscanf(ptrthree,"%s",save_hour);			//doc gio
			fscanf(ptrthree,"%s",save_min);				//doc phut
			fscanf(ptrthree,"%s",save_day);				//doc ngay
			fscanf(ptrthree,"%s",save_month);			//doc thang	
			fscanf(ptrthree,"%s",save_year);			//doc nam
			fgets(info,sizeof info,ptrthree);			// fgets :se doc tiep phan con lai...Name
			if(strcmp(cccd,passport)==0){			//strcmp: so sanh 2 chuoi. so sanh CCCD nhap tu ban phim VS CCCD doc tu file.
				toado(32,10);
				printf("%c %s %c",4,"Can cuoc cong dan / Passport da ton tai. Vui long kiem tra lai ",4);
				toado(25,16);
				printf("%c %s %s",3,"So phong :",room);		
				toado(25,17);
				printf("%c %s %s",3,"Can cuoc cong dan/ Passport : ",passport); 			
				toado(25,18);
				printf("%c %s %s",3,"Name : ",info);//in name
				toado(25,19);
				printf("%c %s",3,"Ngay/gio dat phong :");
				toado(47,19);
				printf("%s %s",save_hour,"gio");	//in gio dat phong
				toado(55,19);
				printf("%s %s",save_min,"phut");	//in phut dat phong
				toado(65,19);
				printf("%s %s","Ngay ",save_day);	//in ngay dat phong
				toado(75,19);
				printf("%s %s","Thang ",save_month);//in thang dat phong
				toado(85,19);
				printf("%s %s","Nam ",save_year);	//in nam dat phong	
				prime=MENU;
				getch();
				break;
			}	
		}
	}
	fclose(ptrtwo);
	fclose(ptrthree);
}
/*
@Description : kiem tra thoi gian Tra Phong co hop le hay khong
@total_day :tong so ngay trong thang */
void check_time_end(){
	if(prime==DATPHONG){
		int ok,total_day;
		if(hour_end>23||hour_end<0||minute_end>59||minute_end<0){	//kiem tra gio/phut
			toado(35,15);
			mausac(206);
			printf("%c %s %c",4,"Warning: Hour / Minutes unknown .Check again, Please ",4);
			toado(50,16);
			printf("Gio :0-23h - Phut :0-59'");
			prime=MENU;
		}
		if(year_end%4==0||year_end%400==0){							//kiem tra xem co phai nam nhuan ko, de kiem tra thang2 có 28 hay 29 ngay
			ok=1;													//dung la nam nhuan thi gan ok=1;
		}
		if(year_end<0){
			toado(37,24);
			mausac(206);
			printf("%c %s %c",4,"Warning: Year Unknown .Check again, Please ",4);
			prime=MENU;
		}
		if(month_end>=0&&month_end<=12){							//Dinh nghia so ngay trong thang
			switch(month_end){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:	
					total_day=31;									//Neu la thang 1,3,5,7,8,10,12 thi se co tong 31 ngay.
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					total_day=30;
					break;
				case 2:
					if(ok==1){										//neu ok=1 thi day la nam nhuan .nen Thang 2 co 29 ngay
						total_day=29;
					}
					else{
						total_day=28;								//neu ko se la 28 ngay
					}
					break;	
				default:
					total_day=0;							
			}
		}else{
			toado(37,21);
			mausac(206);
			printf("%c %s %c",4,"Warning: Day / Month Unknown .Check again, Please ",4);
			toado(50,22);
			printf("Day :1-31 - Month :1-12");
			prime=MENU;
		}
		if(day_end<1||day_end>total_day){
			toado(37,18);
			mausac(206);
			printf("%c %s %c",4,"Warning :Day / Month Unknown .Check again, Please ",4);
			toado(50,19);
			printf("Day :1-31 - Month :1-12");
			prime=MENU;
		}
	}
}
/*
@Description :tính thoi gian thue phong(gio/phut) chi dem trong pham vi 1 nam, ko dem dc 2 nam lien tiep
@mktime() chuyen tu tm sang time_t
@time(): lay thoi gian hien tai cua he thong
@difftime() tinh hieu giua 2 khoang thoi gian hien tai va khi tra phong, tra ve tong so giay
@struct tm : cau truc tm chua lich va ngay duoc chia nho thanh cac thanh phan,duoc dinh dang san trong thu vien
@localtime():chuyen tu dinh dang tu time_t sang struct tm(int)*/
int hour_total_int; //khai bao ben ngoai ham de su dung cho cac ham khac
void count_time(){
	time_t currently;						//khai bao bien currently dang time_t....thoi gian hien tai
	time(&currently);	
	struct tm *end=localtime(&currently);	// gan localtime()cho con tro *end 
	end->tm_hour=hour_end;						//tm_hour(0-23)
	end->tm_min=minute_end;						//tm_min(0-59)
	end->tm_mday=day_end;						//tm_day(1-31)
	end->tm_mon=month_end-1;					//tm_mon(0-11)
	double second=difftime(mktime(end),currently);				//hieu giua 2 khoang thoi gian tra phong-dat phong ***tra ve tong so giay(s)
	hour_total_int		=second/3600;							//gio so nguyen(lam tron)
	float 	hour_total_float	=second/3600;  							//gio so thuc
	float	minute_total		=(hour_total_float-hour_total_int)*60; 	// chuyen doi tu "gio thap phan" sang "gio/phut"
	toado(20,18);
	printf("%c %s %d %s %0.0f %s",3,"SO THOI GIAN THUE PHONG LA :",hour_total_int,"gio",minute_total,"phut");
}
/*
@Description:Khai bao bien toan cuc...tat cac se dùng chung bien nay.
luu gia tri thoi gian "hien tai" cua he thong*/
int hour_now;
int min_now;
int day_now;
int month_now;
int year_now;
/*
@Description:hien thi thoi NHAN-TRA PHONG theo gio he thong
@Struct tm : cau truc chua lich va ngay chia nho theo cac thanh phan .duoc dinh nghia san trong thu vien 
@localtime :chuyen doi tu dang "time_t" sang "tm" (int)
@localtime(&cur) : la thoi gian hien tai cua he thong o dang tm
@khai bao ham time() de lay ngay gio hien tai cua he thong
@time_t :dang thoi gian*/
void display_time(){ 	
	time_t cur;
	time(&cur);	
	struct tm *now=localtime(&cur);	
	//
	hour_now	=	now->tm_hour;		//gan thoi gian hien tai cho"bien" dc khai bao o phia tren kia
	min_now		=	now->tm_min;
	day_now		=	now->tm_mday;
	month_now	=	now->tm_mon+1;
	year_now	=	now->tm_year+1900;
	//
	toado(20,12);
	printf("%c %s",3,"THOI GIAN NHAN PHONG :\n");
	toado(20,13);
	printf("%d %s",hour_now,"gio ");		//gio
	printf("%d %s",min_now,"phut ");		//phut
	printf("%s %d"," ngay ",day_now);		//ngay	   //in thoi gian hien tai (dat phong),
	printf("%s %d"," thang ",month_now);	//thang
	printf("%s %d"," nam ",year_now);		//nam         tm_year:dem so nam tu 1900->nay....+1900=2021 
	printf("\n \n");
	// 
	toado(20,15);
	printf("%c %s",3,"THOI GIAN TRA PHONG :\n");
	toado(20,16);
	printf("%d %s",hour_end,"gio ");
	printf("%d %s",minute_end,"phut ");
	printf("%s %d"," ngay ",day_end);			
	printf("%s %d"," thang ",month_end);
	printf("%s %d"," nam ",year_end);
}

/*
@Description : tinh tien phong 2 giuong
@hour_total_int : tong so thoi gian thue(gio), bien nay da duoc tinh o ham count_time*/
void pay_two_bed(){
	toado(20,20);
	printf("%c %s",3,"Phong 2 giuong : ");
	if(hour_total_int==24){					//neu thue 24h(1 ngay)
		printf(" Thanh tien :280.000 VND");
	}
	if(hour_total_int>24){					//neu thue >24h(>1 ngay)
		printf("%s %d %s"," Thanh tien:",280000+(15000*(hour_total_int-24))," VND");
	}
	if(hour_total_int<24){
		if(hour_now>=19&&hour_end<=9){		//gio bat dau phai >=19h va gio tra phong <=9h thi tinh la QUA DEM
			printf("Thanh tien : 150.000 VND");
		}
		if(hour_now<24&&hour_end<=23){		//neu gio bat dau <19h va ket thuc <=23h
			if(hour_total_int<=2){
				printf(" Thanh tien : 80.000 VND");
			}
			if(hour_total_int>2){
				printf("%s %d %s"," Thanh tien :",80000+(15000*(hour_total_int-2))," VND");
			}		 		
		}
	}
}
/*
@Description : tinh tien phong 3 giuong
@cac thong so tuong tu nhu ham pay_two_bed chi khac gia tien */
void pay_three_bed(){
	toado(20,20);
	printf("%c %s",3,"Phong 3 giuong : ");
	if(hour_total_int==24){					//neu thue 24h(1 ngay)
		printf("350.000 VND");
	}
	if(hour_total_int>24){					//neu thue >24h(>1 ngay)
		printf("%s %d %s","Thanh tien :",350000+(15000*(hour_total_int-24))," VND");
	}
	if(hour_total_int<24){
		if(hour_now>=19&&hour_end<=9){		//gio bat dau phai >=19h va gio tra phong <=9h thi tinh la QUA DEM
			printf("Thanh tien : 180.000 VND");
		}
		if(hour_now<24&&hour_end<=23){		//neu gio bat dau <19h va ket thuc <=23h
			if(hour_total_int<=2){
				printf("Thanh tien  : 100.000 VND");
			}
			if(hour_total_int>2){
				printf("%s %d %s","Thanh tien :",100000+(15000*(hour_total_int-2))," VND");
			}
		}	
	}
}
/*
@Description : chon phong 2 giuong hoac 3 giuong
chon loai nao se hien thi thong tin loai do */
void datphong(){
	if(prime==DATPHONG){
		system("cls");
		mausac(121);
		toado(50,2);
		printf("%c %s %c",3,"JAV HOTEL",3);
		toado(35,4);
		printf("%c %s %c",4," Moi quy khach chon dich vu ",4,"\n");
		toado(44,6);
		printf("Phong 2 giuong.\n");
		toado(44,7);
		printf("PHong 3 giuong.\n");
		toado(44,8);
		printf("Tro ve.\n");
		toado(42,6);					//vi tri ban dau cua con tro 
		printf("%c",16);
		int choice=1;
		int key;
		while(prime==DATPHONG){				
			if(kbhit()){
				key=getch();
				if(key==80){		//***neu key==80 (80: phim mui ten xuong tren ban phim)
					choice++;
					if(choice==4){
						choice=1;	//gan lai choice=1 de choice ko bi qua lon chay tu case 2
					}	
				}
				if(key==72){		//***neu an phim 72(phim mui ten di len tren ban phim)
					choice--;
					if(choice==0){
						choice=3;	//gan lai choice==2 de con tro hien thi o dong 2 chay tu case 2->1
					}
				}
				switch(choice){
					case 1:
						toado(42,7);
						printf(" ");
						toado(42,8);
						printf(" ");
						toado(42,6);
						printf("%c",16);
						break;	
						
					case 2:
						toado(42,6);
						printf(" ");
						toado(42,8);
						printf(" ");
						toado(42,7);
						printf("%c",16);
						break;	
					case 3:	
						toado(42,6);
						printf(" ");
						toado(42,7);
						printf(" ");
						toado(42,8);
						printf("%c",16);
				}
				if(key==13){
					switch(choice){
						case 1:
							prime=TWOBED;
							break;
						case 2:
							prime=THREEBED;
							break;
						case 3:
							prime=MENU;
							break;	
					}	
				}	
			}		
		}
	}
	else{
		prime=MENU;
	}
}
/*
@Description : Tu dong xep phong 2 giuong cho khach hang..neu phong da ton tai,se xep phong khac  khong trung nhau
@list_room_two : danh sach cac phong 2 giuong
@room[] :luu cac phan tu sau khi chuyen doi tu int ->string cua list_room_two de so sanh voi read_room[] doc tu file
@info[] :thong tin sau khi doc tu file se dc luu vao cac mang nay
@count : dem so lan giong nhau giua so phong va so phong trong file */
void Auto_room_two_bed(){
	int count=0;
	system("cls");
	toado(50,2);
	printf("%c %s %c",3,"JAV HOTEL",3);
	char room[3],read_room[3],info[70];
 	int i;
	FILE*doc = fopen("infotwobed.txt","r");		//chi doc
	FILE*ghi = fopen("infotwobed.txt","a");		//chi ghi..neu gop chung doc+ghi thi file se ko ghi duoc...that la cam giac
	int list_room_two[]={201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220};
		for(i=0;i<20;i++){
			itoa(list_room_two[i],room,10);		//chuyen int sang string-> roi luu vao mang room[] de so sanh vs read_room[] doc tu file
			while(!feof(doc)){
				fscanf(doc,"%s",read_room);		//doc tung doan file,  lay thong tin room de so sanh .
				fgets(info,sizeof info,doc);	//doc not doan con lai trong file
				if(strcmp(room,read_room)==0){	//so sanh so phong da dat vs so phong hien tai, neu ko trung nhau thi count++ ..lap tiep..
					count++;
					if(i==19){
						mausac(206);
						toado(36,6);
						printf("Da het phong. Quy khach vui long quy lai sau !");
						prime=MENU;				//neu het phong thi se gan prime=MENU, lam dieu kien cho fuction write_file_two/three
					}
				}
			}
			fseek(doc,0,SEEK_SET);				//dat con tro file ve vi tri ban dau, de cho i tiep theo duoc so sanh tu dau file
			if(count==0){						//neu count==0, nghia la ko co gia tri nao trong file trung khop(tuc la phonng chua co ai dat) thi se dat phong cho khach
				toado(43,4);
				printf("Xac nhan dat phong Thanh Cong !");
				toado(40,6);
				printf("Phong cua Quy Khach la Phong So : %s",room); //in so phong len man hinh console
				fprintf(ghi,"%s ",room);		//neu khong trung nhau thi se gan so phong nay cho khach hang va luu vao file listroom.txt
				break;
			}
			count=0;							//gan lai count==0 de dem lai tu dau	
		}		
	fclose(doc);								
	fclose(ghi);		
	toado(43,12);
	printf("_An phim bat ki de tro ve Menu_");
	getch();		
}	
/*
@Description : Tu dong xep phong 3 giuong cho khach, neu phong da ton tai,se xep phong khac khong trung nhau
@list_room_three : danh sach cac phong 3 giuong  
@room[] : mang luu cac phan tu cua list_room_two de so sanh voi-> read[] :luu chuoi doc tu file
@info[] :thong tin sau khi doc tu file se dc luu vao cac mang nay
@count : dem so lan giong nhau giua so phong va so phong trong file   */
void Auto_room_three_bed(){
	int count=0;
	system("cls");
	toado(50,2);
	printf("%c %s %c",3,"JAV HOTEL",3);
	char room[3],read_room[3],info[70];
	int i;
	FILE*doc = fopen("infothreebed.txt","r");	//chi doc
	FILE*ghi = fopen("infothreebed.txt","a");	//chi ghi..neu gop chung doc+ghi thi file se ko ghi duoc...that la cam giac
	int list_room_three[]={301,302,303,304,305,306,307,308,309,310,311,312,313,314,315};
		for(i=0;i<15;i++){
			itoa(list_room_three[i],room,10);	//chuyen int sang string-> roi luu vao mang room[] de so sanh vs read_room[] doc tu file
			while(!feof(doc)){
				fscanf(doc,"%s",read_room);		//doc tung doan file, nhug chi lay thong tin room de so sanh la dc .
				fgets(info,sizeof info,doc);	//doc not doan con lai trong file	
				if(strcmp(room,read_room)==0){	//so sanh so phong da dat vs so phong hien tai, neu trung nhau thi count++..lap tiep
					count++;					//neu co phong nao giong nhau thi count++
					if(i==19){
						mausac(206);
						toado(36,6);
						printf("Da het phong. Quy khach vui long quy lai sau !");
						prime=MENU;				//neu het phong thi se gan prime=MENU, lam dieu kien cho fuction write_file_two/three
					}
				}
			}
			fseek(doc,0,SEEK_SET);
			if(count==0){						//neu count==0, nghia la ko co gia tri nao trong file trung khop(tuc la phonng chua co ai dat) thi se dat phong cho khach
				toado(43,4);
				printf("Xac nhan dat phong Thanh Cong");
				fprintf(ghi,"%s ",room);		//neu khong trung nhau thi se gan so phong room[i] cho khach hang, va luu vao file listroom.txt
				toado(40,6);
				printf("Phong cua Quy Khach la Phong So : %s",room);
				break;
			}
			count=0;							//gan lai count==0 de dem lai tu dau.
		}
	fclose(doc);
	fclose(ghi);
	toado(43,12);
	printf("_An phim bat ki de tro ve Menu_");
	getch();
	
}	
	
/*
@Description :ghi thong tin DAT PHONG 2 giuong cua khach hang vao file
@cccd[]:luu tam thong tin Can cuoc cong dan/Passport -> de ghi vao file
@name[]:luu tam thong tin ten khach hang ->de ghi vao file
*/
void write_file_two_bed(){
	if(prime!=MENU){		//neu function Auto_room_two/three tra ve prime=MENU( nghia la het phong) thi se ko luu info vao file
		FILE*save = fopen("infotwobed.txt","a");
		fprintf(save,"%s %d %d %d %d %d %s\n",cccd,hour_now,min_now,day_now,month_now,year_now,name);	//ghi vao file can cuoc--gio/phut/ngay/thang/nam dat phong --Ten khach hang
		fclose(save);
	}
	prime=MENU;				//gan lai prime=0(MENU) de switch trong ham main thuc thi tro ve display_menu
}
/*
@Description :ghi thong tin DAT PHONG 3 giuong cua khach hang vao file
@cccd[]:luu tam thong tin Can cuoc cong dan/Passport -> de ghi vao file
@name[]:luu tam thong tin ten khach hang ->de ghi vao file
*/
void write_file_three_bed(){
	if(prime!=MENU){		//neu function Auto_room_two/three tra ve prime=MENU( nghia la het phong) thi se ko luu info vao file
		FILE*save = fopen("infothreebed.txt","a");		
		fprintf(save,"%s %d %d %d %d %d %s\n",cccd,hour_now,min_now,day_now,month_now,year_now,name);	//ghi vao file can cuoc--gio/phut/ngay/thang/nam dat phong --Ten khach hang
		fclose(save);
	}
	prime=MENU;				//gan lai prime=0(MENU) de switch trong ham main thuc thi tro ve display_menu
}
//@khi bao mang de nhap CCCS/Passport can xoa.
char std_cccd[30];
//@nhap thong tin vao std[]
void input_passport_want_delete(){
	system("cls");
	mausac(124);
	toado(50,1);
	printf("%c %s %c",3,"JAV HOTEL",3);
	toado(47,3);
	printf("%c %s %c",4,"Xoa Thong Tin Phong",4);
	toado(40,5);
	printf("Nhap Can cuoc cong dan/ Passport : ");
	gets(std_cccd);
}
/*
*@Description:tim va hien thi thong tin khach hang theo CCCD/Passport.
@tim thong tin khach hang va hien thi thong tin  cua khach hang.
@std_cccd[] : luu chuoi nhap tu ban phim
@passport[30],save_hour[2],save_min[2],save_day[2],save_month[2],save_year[4],info[40] : luu thong tin tu file de xuat ra man hinh tuong ung cac thanh phan*/
void search_info_in_system(){
	int ok;
	char room[2],passport[30],save_hour[2],save_min[2],save_day[2],save_month[2],save_year[4],info[40];
	FILE*ptrtwo=fopen("infotwobed.txt","r");		//doc file info 2 giuong
	FILE*ptrthree=fopen("infothreebed.txt","r");	//doc file info 3 giuong	
	while(!feof(ptrtwo)){						//ham feof : kiem tra xem 1 file da het hay chua. 
		fscanf(ptrtwo,"%s",room);
		fscanf(ptrtwo,"%s",passport);			//fscanf :doc file theo dinh dang... doc den khoang trang se Stop.///doc tung dong trong file	
		fscanf(ptrtwo,"%s",save_hour);			//doc gio
		fscanf(ptrtwo,"%s",save_min);			//doc phut
		fscanf(ptrtwo,"%s",save_day);			//doc ngay
		fscanf(ptrtwo,"%s",save_month);			//doc thang	
		fscanf(ptrtwo,"%s",save_year);			//doc nam
		fgets(info,sizeof info,ptrtwo);			// fgets :se doc tiep phan con lai...Name
		if(strcmp(std_cccd,passport)==0){			//strcmp: so sanh 2 chuoi. so sanh CCCD nhap tu ban phim VS CCCD doc tu file (luu trong passport[])	
			toado(25,7);
			printf("%c %s %s",3,"So phong :",room);		
			toado(25,8);
			printf("%c %s %s",3,"Can cuoc cong dan/ Passport : ",passport); 			//neu dung thi in ra thong tin duoc luu trong mang passport[]
			toado(25,9);
			printf("%c %s %s",3,"Name : ",info);//in name
			toado(25,10);
			printf("%c %s",3,"Ngay/gio dat phong :");
			toado(47,10);
			printf("%s %s",save_hour,"gio");	//in gio dat phong
			toado(55,10);
			printf("%s %s",save_min,"phut");	//in phut dat phong
			toado(65,10);
			printf("%s %s","Ngay ",save_day);	//in ngay dat phong
			toado(75,10);
			printf("%s %s","Thang ",save_month);//in thang dat phong
			toado(85,10);
			printf("%s %s","Nam ",save_year);	//in nam dat phong	
			ok=1;
			break;
		}	
	}
	if(ok!=1){
		while(!feof(ptrthree)){							//ham feof : kiem tra xem 1 file da het hay chua. 
			fscanf(ptrthree,"%s",room);
			fscanf(ptrthree,"%s",passport);				//fscanf :doc file theo dinh dang... doc den khoang trang se Stop.///doc tung dong trong file	
			fscanf(ptrthree,"%s",save_hour);			//doc gio
			fscanf(ptrthree,"%s",save_min);				//doc phut
			fscanf(ptrthree,"%s",save_day);				//doc ngay
			fscanf(ptrthree,"%s",save_month);			//doc thang	
			fscanf(ptrthree,"%s",save_year);			//doc nam
			fgets(info,sizeof info,ptrthree);			// fgets :se doc tiep phan con lai...Name
			if(strcmp(std_cccd,passport)==0){				//strcmp: so sanh 2 chuoi. so sanh CCCD nhap tu ban phim VS CCCD doc tu file (luu trong passport[])	
				toado(25,7);
				printf("%c %s %s",3,"So phong : ",room);
				toado(25,8);
				printf("%c %s %s",3,"Can cuoc cong dan/ Passport : ",passport); 			//neu dung thi in ra thong tin duoc luu trong mang passport[]
				toado(25,9);
				printf("%c %s %s",3,"Name : ",info);//in name
				toado(25,10);
				printf("%c %s",3,"Ngay/gio dat phong :");
				toado(47,10);
				printf("%s %s",save_hour,"gio");	//in gio dat phong
				toado(55,10);
				printf("%s %s",save_min,"phut");	//in phut dat phong
				toado(65,10);
				printf("%s %s","Ngay ",save_day);	//in ngay dat phong
				toado(75,10);
				printf("%s %s","Thang ",save_month);//in thang dat phong
				toado(85,10);
				printf("%s %s","Nam ",save_year);	//in nam dat phong	
				ok=1;
				break;	
			}
		}
	}
	fclose(ptrtwo);
	fclose(ptrthree);
	if(ok!=1){
		toado(47,9);
		printf("THONG TIN KHONG TON TAI !");
		toado(45,15);
		printf("_An phim bat ki tro ve Menu_");
		getch();
		prime=MENU;	
	}
}
/*
@Description :doc thong tin tu file goc, roi copy sang file phu,ngoai tru thong tin can xoa thi ko copy...
nghia la luc nay ta da co 1 file phu chua thong tin sau khi xoa.
@sophong[3] :luu thong tin so phong doc tu file	(buffer)
@cccd[15] 	:luu thong tin cccd doc tu file	(buffer)
@conlai[60] :luu not cac thanh phan con lai cua 1 line (buffer) 
@count : dem so lan trung khop cua cccd nhap tu ban phim va cccd trong file */
void twobed_copy_info_oldfile_to_newfile_and_delete(){
	int count=0;
	char sophong[3],cccd[15],conlai[60];
	FILE*two_old = fopen("infotwobed.txt","r");			//doc thong tin file 2 giuong
	FILE*two_new = fopen("trunggiantwobed.txt","a");	//ghi thong tin file 2 giuong vao file phu( ngoai tru thong tin can xoa)
	while(!feof(two_old)){						
		fscanf(two_old,"%s",sophong);
		fscanf(two_old,"%s",cccd);
		fgets(conlai,sizeof conlai,two_old);
		if(strcmp(std_cccd,cccd)==0){		//neu 2 thong tin cccd/passport trung nhau thi count++, ko ghi vao file phu
			count++;
		}
		else{								//chi ghi nhung thong tin khac voi cccs/passport nhap tu ban phim vao file phu
			if(!feof(two_old)){				//neu end of file thi ko fprintf vao file phu nua .
				fprintf(two_new,"%s %s %s",sophong,cccd,conlai);
			}							
		}
	}		
	fclose(two_old);	
	fclose(two_new);
	char old_name[]="trunggiantwobed.txt";		//ten cu cua file phu
	char new_name[]="infotwobed.txt";	//ten moi cua file phu
	remove("infotwobed.txt");				//xoa file goc
	rename(old_name,new_name);				//sau khi xoa file goc , thi rename file phu==ten file goc ban dau. Luc nay file phu tro thanh file goc
	if(count!=0){							//neu count!=0, nghia la co file trung nhau thi se stop . ve Menu,ko run function tiep theo nua.
		toado(42,20);
		printf("_Da xoa thong tin thanh cong_");
		getch();
		prime=MENU;	
	}
}
/*
@Description :doc thong tin tu file goc, roi copy sang file phu,ngoai tru thong tin can xoa thi ko copy...
nghia la luc nay ta da co 1 file phu chua thong tin sau khi xoa.
@sophong[3] :luu thong tin so phong doc tu file	(buffer)
@cccd[15] 	:luu thong tin cccd doc tu file	(buffer)
@conlai[60] :luu not cac thanh phan con lai cua 1 line (buffer) 
@count : dem so lan trung khop cua cccd nhap tu ban phim va cccd trong file  */
void threebed_copy_info_oldfile_to_newfile_and_delete(){
	int count=0;
	char sophong[3],cccd[15],conlai[60];
	FILE*three_old = fopen("infothreebed.txt","r");		//doc thong tin file 3 giuong
	FILE*three_new = fopen("trunggianthreebed.txt","a");//ghi thong tin file 3 giuong vao file phu( ngoai tru thong tin can xoa)
	while(!feof(three_old)){						
		fscanf(three_old,"%s",sophong);
		fscanf(three_old,"%s",cccd);
		fgets(conlai,sizeof conlai,three_old);
		if(strcmp(std_cccd,cccd)==0){		//neu 2 thong tin cccd/passport trung nhau thi count++, ko ghi vao file phu
			count++;
		}
		else{								//chi ghi nhung thong tin khac voi cccs/passport nhap tu ban phim vao file phu
			if(!feof(three_old)){			//neu end of file thi ko fprintf vao file phu nua .
				fprintf(three_new,"%s %s %s",sophong,cccd,conlai);
			}							
		}
	}		
	fclose(three_old);
	fclose(three_new);
	char old_name[]="trunggianthreebed.txt";//ten cu cua file phu
	char new_name[]="infothreebed.txt";		//ten moi cua file phu
	remove("infothreebed.txt");				//xoa file goc
	rename(old_name,new_name);				//sau khi xoa file goc , thi rename file phu==ten file goc ban dau. Luc nay file phu tro thanh file goc
	if(count!=0){
		toado(42,20);
		printf("_Da xoa thong tin thanh cong_");
	}
	getch();
	prime=MENU;
}
/*
@Description : xac nhan xoa phong hay khong */
void confirm_delete_info(){
	toado(50,15);
	printf("%c %s",4," Xac nhan");
	toado(50,16);
	printf("%c %s",4," Huy");
	toado(48,15);
	printf("%c",16);
	int choice=1;
	int key;
	while(prime==HUYPHONG){			//neu o datphong() tra ve prime=HUYPHONG thi while se luon dung. 
		if(kbhit()){
			key=getch();
			if(key==80){			//***neu key==80 (80: phim mui ten xuong tren ban phim)
				choice++;
				if(choice==3){
					choice=1;		//gan lai choice=1 de choice ko bi qua lon chay tu case 2
				}	
			}
			if(key==72){			//***neu an phim 72(phim mui ten di len tren ban phim)
				choice--;
				if(choice==0){
					choice=2;		//gan lai choice==2 de con tro hien thi o dong 2. chay tu case 2->1
				}
			}
			switch(choice){
				case 1:
					toado(48,16);		
					printf(" ");
					toado(48,15);
					printf("%c",16);
					break;	
					
				case 2:
					toado(48,15);
					printf(" ");
					toado(48,16);
					printf("%c",16);
					break;	
			}
			if(key==13){
				switch(choice){
					case 1:
						prime=XACNHAN;
						break;
					case 2:
						prime=MENU;
						break;
				}	
			}
		}
	}	
}
/*
@Description: hien thi cac phong trong con lai theo loai
@room[]:luu string sau khi chuyen doi tu int cua list_room_two
@count : dem so lan giong nhau giua so phong va so phong trong file 
@total_room : dem cac phong con lai*/
void check_info_hotel(){
	mausac(125);
	int count=0,total_room=0;
	system("cls");
	toado(50,2);
	Sleep(1);
	printf("%c %s %c",3,"JAV HOTEL",3);
	int i;
	char room[3],info[70],read[3];
	toado(45,5);
	printf("%c %s",4,"CAC PHONG 2 GIUONG CON LAI :\n");
	int list_room_two[] = {201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220};
	FILE*two = fopen("infotwobed.txt","r");	//doc file	
	for(i=0;i<20;i++){
		itoa(list_room_two[i],room,10);		//chuyen (int) list_room_two sang "string" luu vao room[] de so sanh voi read[] doc tu file .
		while(!feof(two)){					//doc den het file  ->>stop
			fscanf(two,"%s",read);			//doc tung doan file, nhug chi lay thong tin room de so sanh la dc .con lai ko quan tam
			fgets(info,sizeof info,two);	//doc not doan con lai
			if(strcmp(room,read)==0){		//so sanh so phong da dat vs so phong hien tai, neu ko trung nhau thi lap tiep...
				count++;					//va tang count len 1 don vi
			}
		}
		fseek(two,0,SEEK_SET);				// dat con tro trong file tro ve vi tri ban dau de doc lai tu dau
		if(count==0){						//neu ko count==0, nghia la ko co gia tri nao trong file trung khop(tuc la phonng chua co ai dat) thi se in ra
			printf("%5s",room);
			total_room++;
		}
		count=0;							//gan lai count==0 de dem lai tu dau.
	}
	toado(75,5);
	printf("%d %s",total_room,"Phong");		//in ra tong so phong con lai
	total_room=0;							//dat lai ve 0 de dem so phong 3 giuong ben duoi.
	fclose(two);
	/////////////////////////////////////
	toado(45,8);
	printf("%c %s",4,"CAC PHONG 3 GIUONG CON LAI :\n");
	FILE*three = fopen("infothreebed.txt","r");	//doc file	
	int list_room_three[] = {301,302,303,304,305,306,307,308,309,310,311,312,313,314,315};
	for(i=0;i<15;i++){
		itoa(list_room_three[i],room,10);	//chuyen (int) list_room_two sang "string" luu vao room[] de so sanh voi read[] doc tu  file .
		while(!feof(three)){				//doc den het file ->>stop
			fscanf(three,"%s",read);		//doc tung doan file, nhug chi lay thong tin room de so sanh la dc .con lai ko quan tam.
			fgets(info,sizeof info,three);
			if(strcmp(room,read)==0){		//so sanh so phong da dat vs so phong hien tai, neu ko trung nhau thi lap tiep....
				count++;					////va tang count len 1 don vi
			}
		}
		fseek(three,0,SEEK_SET);			// dat con tro trong file tro ve vi tri ban dau de doc lai tu dau
		if(count==0){						//neu ko count==0, nghia la ko co gia tri nao trong file trung khop(tuc la phonng chua co ai dat) thi se in ra
			printf("%5s",room);
			total_room++;
		}
		count=0;							//gan lai count==0 de dem lai tu dau.
	}
	toado(75,8);
	printf("%d %s",total_room,"Phong");
	fclose(three);
	//////////////////////////////////
	toado(40,12);
	printf("__vui long an ESC de tro ve voi Quan nao__");
	int key=getch();
	if(key==27){
		prime=MENU;
	}
	else{
		toado(47,14);
		printf("an ESC ban ei ! mu ak");
	}
	
}
/*
@Description : xac nhan dat phong 2 giuong, */
void xac_nhan_two_bed(){
	toado(50,23);
	printf("%c %s",4," Xac nhan");
	toado(50,24);
	printf("%c %s",4," Huy");
	toado(48,23);
	printf("%c",16);
	int choice=1;
	int key;
	while(prime==TWOBED){			//neu o datphong() tra ve prime=TWOBED thi while se luon dung. 
		if(kbhit()){
			key=getch();
			if(key==80){			//***neu key==80 (80: phim mui ten xuong tren ban phim)
				choice++;
				if(choice==3){
					choice=1;		//gan lai choice=1 de choice ko bi qua lon chay tu case 2
				}	
			}
			if(key==72){			//***neu an phim 72(phim mui ten di len tren ban phim)
				choice--;
				if(choice==0){
					choice=2;		//gan lai choice==2 de con tro hien thi o dong 2. chay tu case 2->1
				}
			}
			switch(choice){
				case 1:
					toado(48,24);		
					printf(" ");
					toado(48,23);
					printf("%c",16);
					break;	
					
				case 2:
					toado(48,23);
					printf(" ");
					toado(48,24);
					printf("%c",16);
					break;	
			}
			if(key==13){
				switch(choice){
					case 1:
						prime=XACNHAN;
						break;
					case 2:
						prime=MENU;
						break;
				}	
			}
		}
	}
}
/*
description : xac nhan phong 3 giuong*/
void xac_nhan_three_bed(){
	toado(50,23);
	printf("%c %s",4," Xac nhan");
	toado(50,24);
	printf("%c %s",4," Huy");
	toado(48,23);
	printf("%c",16);
	int choice=1;
	int key;
	while(prime==THREEBED){			//neu o datphong() tra ve prime=THREEBED thi while se luon dung
		if(kbhit()){
			key=getch();
			if(key==80){			//***neu key==80 (80: phim mui ten xuong tren ban phim)
				choice++;
				if(choice==3){
					choice=1;		//gan lai choice=1 de choice ko bi qua lon chay tu case 2
				}	
			}
			if(key==72){			//***neu an phim 72(phim mui ten di len tren ban phim)
				choice--;
				if(choice==0){
					choice=2;		//gan lai choice==2 de con tro hien thi o dong 2. chay tu case 2->1
				}
			}
			switch(choice){
				case 1:
					toado(48,24);
					printf(" ");
					toado(48,23);
					printf("%c",16);
					break;	
					
				case 2:
					toado(48,23);
					printf(" ");
					toado(48,24);
					printf("%c",16);
					break;	
			}
			if(key==13){			//neu Enter thi chay switch()
				switch(choice){
					case 1:
						prime=XACNHAN;	
						break;
					case 2:
						prime=MENU;
						break;
				}	
			}
		}
	}			
}

int main(){
prime=MENU;				// 1.gan prime==0(MENU)
display_menu();			// 2.roi chay ham Display_menu
	while(1){
		switch(prime){
			case MENU:					//=0
				display_menu();
				break;
			case DATPHONG:				//=1
				mausac(125);
				stdin_infomation();						//nhap ten va cccd va thoi gian Tra Phong
				check_cccd_passport_input();			//check thong tin da co hay chua
				stdin_time();							//nhap thoi gian Tra Phong
				check_time_end();
				datphong();								//chon kieu phong 2 giuong hoac 3 giuong
				switch(prime){
					case TWOBED:		//=	5
						display_time();					//hien thi gio nhan/tra	
						count_time();					//tinh thoi gian tu luc datphong ->tra phong ( tinh ra tong so gio/phut/giay)
						pay_two_bed();					//tinh gia tien phong 2 giuong dua vao thoi gian thue
						xac_nhan_two_bed();				//xac nhan.
						switch(prime){
							case XACNHAN ://=7
								Auto_room_two_bed();	//auto xep phong 2 giuong cho khach theo thu tu
								write_file_two_bed();	//ghi tong tin ten/cccd/ngay gio dat phong vao file.
								break;
							case MENU:	//0
								break;	
						}
						break;			//break TWOBED
					case THREEBED:		//= 6
						display_time();
						count_time();
						pay_three_bed();
						xac_nhan_three_bed();
						switch(prime){
							case XACNHAN://=7
								Auto_room_three_bed();						//ghi ten phong vao file truoc
								write_file_three_bed();						//tiep theo se ghi not thong tin khach hang vao file
								break;
							case MENU:	//=0
								break;	
						}
						break;			//break case THREEBED
				}
				break;					//break case DATPHONG
			case HUYPHONG:				//=2
				input_passport_want_delete();								//nhap cccd/Passport
				search_info_in_system();									//kiem tra thong tin trong file va hien thi
				confirm_delete_info();
				switch(prime){
					case XACNHAN:		//=7
						twobed_copy_info_oldfile_to_newfile_and_delete();	//check file 2 giuong, neu co thi xoa
						threebed_copy_info_oldfile_to_newfile_and_delete();	//check file 3 giuong, neu co thi xoa
						break;
					case MENU :			//=0
						break;
				}
				break;
			case INFOHOTEL :			//=3
				check_info_hotel();
				break;
			case EXIT:	
					toado(35,12);
					mausac(125);				//=4
					printf("%c %s %c",3,"Cam on quy khach da su dung dich vu. See you again",3);
					getch();
					exit(0);
				break;
		}
	
	}
		
		
	return 0;
}


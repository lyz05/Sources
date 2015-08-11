{	��ÿ����ı�ŷ�ʽΪ��ǰ���((x-1)+y)<<1ֵ������odd��Ϊ�����
	�ñ�������
}
uses	math;
const
	Maxn=105;Maxm=105;Maxt=Maxn*Maxm<<1+1;Maxs=0;
	Maxe=(Maxn*Maxm*10+Maxn*Maxm)<<1;
	Maxl=55;							//��ĸ�����ܹ�����ĸ
	maxx=Maxlongint>>1;
	Alpha='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';	//�����Ӧ����
var
	Direct:array[1..8,1..2]of longint=((1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1));
	Tov,Next,f,v,Re:array[1..Maxe]of longint;			
	//Tov��ָ���Ŀ�꣬next��һ���ٽӱߵ�λ�ã�re�߶�Ӧ�ķ����
	Mat:array[1..Maxn,1..Maxm]of longint;				//������ַ�ʹ�ô���
	e,dis:array[Maxs..Maxt]of longint;
	Ch:array[1..Maxn,1..Maxm]of char;				//������ַ�����
	Stack:array[1..Maxt]of longint;
	p:array[1..Maxl]of longint;
	w:string;							//��ѯ�ĵ���
	Tot,n,m,Len,s,t,Cnt,tt:longint;
	MaxFlow:int64;
function Get(x,y:longint):longint;
begin
	exit((x-1)*m+y);
end;

function ID1(x,y:longint):longint;
begin
	exit(Get(x,y)<<1-1);
end;

function ID2(x,y:longint):longint;
begin
	exit(Get(x,y)<<1);
end;

procedure add(x,y,Full,Rev:longint);
begin
	inc(Tot);
	Tov[Tot]:=y;
	f[Tot]:=Full;
	Re[Tot]:=Tot+Rev;
	//tot�߶�Ӧ�ķ����
	Next[Tot]:=e[x];
	e[x]:=Tot;
end;

procedure Build(x,y,Full:longint);
begin
	add(x,y,Full,1);
	add(y,x,0,-1);
	//��������ߣ�����������
end;

function Bfs:boolean;				//���Ѹ�·�����
var
	i,x,y,Head,Tail:longint;
begin
	Head:=0;
	Tail:=1;
	Stack[1]:=s;
	fillchar(dis,sizeof(dis),0);
	dis[s]:=1;
	repeat
		inc(Head);
		x:=Stack[Head];
		i:=e[x];
		while i<>0 do
		begin
			y:=Tov[i];
			if (f[i]-v[i]>0) and (dis[y]=0) then
			begin
				dis[y]:=dis[x]+1;
				inc(Tail);
				Stack[Tail]:=y;
			end;
			i:=Next[i];
		end;
	until Head=Tail;
	exit(dis[t]<>0);
end;

function Aug(x,Flow:longint):longint;		
//dfs,f��ʾ����������������,v��ʾ�Ѿ���������������flow�����������������
var
	Temp,i,y:longint;
begin
	if x=t then
		exit(Flow);
	Aug:=0;
	i:=e[x];
	while i<>0 do
	begin
		y:=Tov[i];
		if (f[i]-v[i]>0) and (dis[y]=dis[x]+1) then	//��һ������ı�
		begin
			Temp:=Aug(y,Min(Flow,f[i]-v[i]));
			if Temp>0 then
			begin
				inc(v[i],Temp);
				dec(v[Re[i]],Temp);
				inc(Aug,Temp);
				dec(Flow,Temp);
				if Flow=0 then		//����·���Ѿ�����
					break;
			end;
		end;
		i:=Next[i];
	end;
end;

procedure Scanf;
var	i,j:longint;
begin
	fillchar(Tov,sizeof(Tov),0);
	fillchar(Next,sizeof(Next),0);
	fillchar(f,sizeof(f),0);
	fillchar(v,sizeof(v),0);
	fillchar(Re,sizeof(Re),0);
	fillchar(e,sizeof(e),0);
	fillchar(p,sizeof(p),0);
	Tot:=0;
	readln(n,m);
	for i:=1 to n do
	begin
		for j:=1 to m do read(Ch[i,j]);
		readln;
	end;
	for i:=1 to n do
	begin
		for j:=1 to m do read(Mat[i,j]);
		readln;
	end;
	readln(w);

	Len:=length(w);
	for i:=1 to Len do p[pos(w[i],Alpha)]:=i;
end;

procedure Solve;
var
	x,y,Drt,Newx,Newy:longint;
begin
	s:=0;
	t:=n*m*2+1;
	for x:=1 to n do
		for y:=1 to m do
		begin
			if Ch[x,y]=w[1] then
				Build(s,ID1(x,y),maxx);
			if Ch[x,y]=w[Len] then
				Build(ID2(x,y),t,maxx);
			//Դ���㴦��
			Build(ID1(x,y),ID2(x,y),Mat[x,y]);
			//�����ɱ�
			for Drt:=1 to 8 do
			begin
				Newx:=x+Direct[Drt,1];
				Newy:=y+Direct[Drt,2];
				if (1<=Newx) and (Newx<=n) and (1<=Newy) and (Newy<=m) then
					//Ŀ����ĸ�Ϸ�
					if (p[pos(Ch[x,y],Alpha)]<>0) and (p[pos(Ch[Newx,Newy],Alpha)]<>0) then
						//��ǰ��ĸ��Ŀ����ĸ���ڵ����г���
						if p[pos(Ch[x,y],Alpha)]+1=p[pos(Ch[Newx,Newy],Alpha)] then
						//��ǰ��ĸ��Ŀ����ĸ�ڵ���������
						Build(ID2(x,y),ID1(Newx,Newy),maxx);
			end;
		end;
	//NetWork_Flow
	MaxFlow:=0;
	while Bfs do
		inc(MaxFlow,Aug(s,maxx));
end;

begin
	assign(input,'4003.in');reset(input);
	assign(output,'4003.out');rewrite(output);
	readln(tt);
	for cnt:=1 to tt do begin
		Scanf;
		Solve;
		writeln('Case #',cnt,': ',MaxFlow);
	end;
	close(input);close(output);
end.

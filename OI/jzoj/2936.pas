const maxn=100000;
type	arr=array[0..maxn,1..3] of longint;
var	i,j,k,n:longint;
	a,h,hh:array[0..maxn] of longint;
	b:arr;
	p:array[0..maxn] of boolean;
	flag:boolean;
	ans:int64;
function gf(x:longint):longint;
begin
	if h[x]=x then exit(x);
	h[x]:=gf(h[x]);
	exit(h[x]);
end;
procedure link(x,y:longint);
var	i,j:longint;
begin
	i:=gf(x);j:=gf(y);
	if i<>j then h[i]:=j;
end;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j:longint;
begin
	m:=a1[(l+r) div 2,3];
	i:=l;j:=r;
	repeat
		while a1[i,3]>m do inc(i);
		while a1[j,3]<m do dec(j);
		if i<=j then begin
			a1[0]:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=a1[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
begin
	assign(input,'2936.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,k);
	for i:=1 to n do begin
		read(a[i]);
		p[a[i]]:=true;
	end;
	for i:=1 to n-1 do begin
		readln(b[i,1],b[i,2],b[i,3]);
	end;
	qsort(b,1,n-1);   

	ans:=0;
	for i:=0 to n-1 do h[i]:=i;
	for i:=1 to n-1 do begin
		link(b[i,1],b[i,2]);
		flag:=false;
		for j:=1 to k do 
			if hh[j]<>h[a[j]] then begin
				hh[j]:=h[a[j]];
				flag:=true;
			end;
		if flag then inc(ans,b[i,3]);
	end;
	writeln(ans);
	//close(input);close(output);
end.

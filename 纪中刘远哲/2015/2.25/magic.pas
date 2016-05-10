uses	math;
const	maxn=1000;maxm=50000;
type	node=record
		y,next:longint;
	end;
	arr=array[0..maxn,1..2] of longint;
var	i,m,n,tot,len,x,y,sum:longint;
	a,b,e:array[1..maxn] of longint;
	h:array[1..maxm] of node;
	s:arr;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j:longint;
begin
	m:=a1[(l+r) div 2,1];
	{m2:=a1[(l+r) div 2,2];}
	i:=l;j:=r;
	repeat
		while (a1[i,1]>m){ or ((a1[i,1]=m) and (a1[i,2]<m2))} do inc(i);
		while (a1[j,1]<m){ or ((a1[j,1]=m) and (a1[j,2]>m2))} do dec(j);
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
function work(x:longint):longint;
var	i,ans,t2:longint;
begin
	fillchar(s,sizeof(s),0);
	len:=0;ans:=0;
	i:=e[x];
	while i<>0 do begin
		inc(len);
		s[len,1]:=a[h[i].y];
		s[len,2]:=b[h[i].y];
		//s[len,3]:=len;
		i:=h[i].next;
	end;
	qsort(s,1,len);
	t2:=0;
	for i:=1 to len do begin
		t2:=t2+s[i,2];
		if (i<>len) and (s[i,1]=s[i+1,1]) then continue;
		if t2<s[i,1] then inc(ans,t2) else begin
			inc(ans,s[i,1]);
			break;
		end;
		t2:=0;
	end;
	exit(ans);
end;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
begin
	assign(input,'input.txt');reset(input);
	assign(output,'output.txt');rewrite(output);

	readln(n,m);
	for i:=1 to n do read(a[i]);
	for i:=1 to n do read(b[i]);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
	end;

	sum:=0;
	for i:=1 to n do begin
		inc(sum,work(i));
	end;
	writeln(sum);

end.

const	maxn=500+5;
type	arr=array[0..maxn+1] of longint;
var	i,j,k,m,n,sum:longint;
	a,b:arr;
	mark:array[0..maxn+1] of longint;
	map:array[1..maxn+1,1..maxn+1] of boolean;
procedure qsort(var a1:arr;l,r:longint);
var m,i,j:longint;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]>m do inc(i);
		while a1[j]<m do dec(j);
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
function judge(x:longint):boolean;
var	i:longint;
begin
	b:=a;
	b[x]:=0;
	qsort(b,1,n+1);
	while b[1]>0 do begin
		for i:=2 to b[1]+1 do begin
			if b[i]-1<0 then exit(false);
			dec(b[i]);
		end;
                b[1]:=0;
		qsort(b,1,n);
	end;
	exit(true);
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	sum:=0;
	readln(n);
	for i:=1 to n+1 do begin
		readln(a[i]);
		inc(sum,a[i]);
	end;
	for i:=1 to n+1 do begin
		if odd(sum-a[i]) then continue;
		if not judge(i) then continue;
		inc(mark[0]);
		mark[mark[0]]:=i;	
	end;
	writeln(mark[0]);
	for i:=1 to mark[0] do writeln(mark[i]);
end.

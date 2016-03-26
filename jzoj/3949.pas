const	maxn=805;maxm=805;
type	arr=array[0..maxn] of longint;
var	i,j,k,m,n,day,l,r,x:longint;
	s:ansistring;		//change
	map:array[1..maxn,1..maxm] of longint;
	dis:arr;
	flag:array[1..maxm,1..maxn] of boolean;
procedure qsort(var a1:arr;l,r:longint);
var m,i,j:longint;
begin
	m:=map[a1[(l+r) div 2],day];
	i:=l;j:=r;
	repeat
		while map[a1[i],day]>m do inc(i);
		while map[a1[j],day]<m do dec(j);
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
	assign(input,'3949.in');reset(input);
	assign(output,'3949.out');rewrite(output);

	readln(n,m,k,x);
	for i:=1 to n do begin
		readln(s);
		dis[i]:=i;
		for j:=length(s) downto 1 do begin
			if s[j]='0' then 
				map[i,j]:=0
			else map[i,j]:=map[i,j+1]+1;
		end;
	end;
	day:=1;
	qsort(dis,1,n);
	for i:=1 to k do 
		flag[1,dis[i]]:=true;

	for i:=2 to m do begin
		flag[i]:=flag[i-1];
		day:=i;
		qsort(dis,1,n);
		l:=1;r:=n;
		for j:=1 to x do begin
			while (l<=n) and (flag[i,dis[l]]) do inc(l);
			while (r>0) and (not flag[i,dis[r]]) do dec(r);
			if l>=r then break;
			flag[i,dis[l]]:=true;
			flag[i,dis[r]]:=false;
		end;
		for j:=1 to n do 
			if flag[i,j] and (map[j,i]=0) then begin
				writeln(-1);
				halt;
			end;
	end;
	for i:=1 to m do begin
		for j:=1 to n do 
			if flag[i,j] then write(j,' ');
		writeln;
	end;
end.

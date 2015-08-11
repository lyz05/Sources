uses	math;
const	maxn=200;
var 	i,j,k,m,n,tot,tmp,l,x,ans:longint;
	a,b:array[0..maxn,1..3] of longint;
	f:array[0..maxn,0..maxn] of longint;
procedure qsort(i,j:longint);
var	l,r,m:longint;
begin
        l:=i;r:=j;
        m:=b[(i+j) div 2,2];
        repeat
        	while b[i,2]>m do inc(i);
		while b[j,2]<m do dec(j);
        	if i<=j then
        	begin
    			b[0]:=b[i];
			b[i]:=b[j];
        	        b[j]:=b[0];
                	inc(i);
                	dec(j);
        	end;
        until i>j;
        if i<r then qsort(i,r);
        if l<j then qsort(l,j);
end;
begin
	readln(n,k);
	for i:=1 to n do readln(a[i,1],a[i,2],a[i,3]);
	for l:=1 to n do begin
		x:=a[l,1];tot:=0;
		for i:=1 to n do
			if ((a[i,3]=0) and (a[i,1]>=x)) or (a[i,3]=1) then
			begin
				inc(tot);
				b[tot]:=a[i];
			end;	
		qsort(1,tot);
		fillchar(f,sizeof(f),0);
		for i:=0 to tot-1 do 
			for j:=0 to i do begin
				if (j<k) and (b[i+1,3]=1) then tmp:=b[i+1,1] else tmp:=0;
				if b[i+1,1]>=x then f[i+1,j+1]:=max(f[i+1,j+1],f[i,j]+tmp);
				if (i-j<k) and (b[i+1,3]=1) then tmp:=b[i+1,2] else tmp:=0;
				f[i+1,j]:=max(f[i+1,j],f[i,j]+tmp);
			end;
		for i:=0 to tot do
			ans:=max(ans,f[tot,i]);
	end;
	writeln(ans);
end.

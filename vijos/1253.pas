var	i,j,k,m,n:longint;
	d1,c,d2,ans:real;
	d,p:array[0..maxn] of real;
begin
	readln(d1,c,d2,p[0],n);
	d[0]:=0;
	for i:=1 to n do readln(d[i],p[i]);
	
	ans:=0;used:=0;w:=0;
	i:=1;
	while i<=n do begin
		if p[i]<=p[i-1] then begin
			tmp:=d[i]-used;
			l:=tmp/d2;
			if l>c then print;

			used:=d[i];
			inc(ans,p[i]);
		end else begin
			min:=maxlongint;k:=0;
			for j:=i to n do begin
				tmp:=d[j]-used;
				l:=tmp/d2;
				if l>c then 
					if j=i then print else break;
				if p[j]<min then begin
					min:=p[j];
					k:=j
				end;
			end;
			
		end;	
	end;
end.

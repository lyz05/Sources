const	maxn=100000;
var	i,j,k,n,m,s,tmp,ans,max,ii,tot:longint;
	a:Array[1..2*maxn] of longint;
begin
	readln(n,s);
	for i:=1 to n do begin
		read(a[i]);
		if a[i]>max then max:=a[i];
	end;
	for i:=n+1 to 2*n do begin
		a[i]:=a[i-n];
	end;
	for ii:=1 to s do begin
		read(m);tmp:=0;ans:=maxlongint;
		if m<max then begin
			writeln('NO');
			continue;
		end;
		for i:=1 to n do begin
			tot:=0;
			for j:=i to i+n-1 do begin
				inc(tmp,a[j]);
				if tmp+a[j+1]>m then begin
					inc(tot);
					tmp:=0;
				end;
			end;
                        if tmp<>0 then inc(tot);
			if tot<ans then ans:=tot;
		end;
		writeln(ans);
	end;
end.

const	maxn=1000000;
var	i,j,k,n,m,s,tmp,ans,max,ii,tot:longint;
	a,b:Array[1..2*maxn] of longint;
begin
	//error at 33 std is 14 my is 15
        assign(input,'data.in');reset(input);
        assign(output,'out.out');rewrite(output);
        readln(n,s);
	for i:=1 to n do begin
		read(a[i]);
		if a[i]>max then max:=a[i];
	end;
	for i:=n+1 to 2*n do begin
		a[i]:=a[i-n];
	end;
	for ii:=1 to s do begin
		read(m);
		fillchar(b,sizeof(b),0);
		tmp:=0;ans:=maxlongint;
		if m<max then begin
			writeln('NO');
			continue;
		end;
		b[1]:=1;
                tmp:=a[1];
		for i:=2 to 2*n do begin
			b[i]:=b[i-1];
			if tmp+a[i]>m then begin
                                inc(b[i]);
                                tmp:=0;
                        end;
                        inc(tmp,a[i]);
		end;
		for i:=1 to n do begin
			tmp:=b[i+n-1]-(b[i]-1);
			if tmp<ans then ans:=tmp;
		end;
		writeln(ans);
	end;
end.

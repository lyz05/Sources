const	maxn=100000;
var	i,j,k,m,n,len:longint;
	a,sum:array[0..maxn] of longint;
	ans,tmp:real;
begin
	//assign(input,'data.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n);
	sum[0]:=0;
	for i:=1 to n do begin
		read(a[i]);
		sum[i]:=sum[i-1]+a[i];
	end;

	sum[0]:=sum[n];
	if n<=15000 then begin
	ans:=maxlongint;
	for i:=2 to n-1 do begin
		for j:=i to n-1 do begin
			len:=n-(j-i+1);
			tmp:=(sum[0]-(sum[j]-sum[i-1]))/len;
			if tmp<ans then begin
                                ans:=tmp;
                        end;
		end;
	end;
	end else begin
	len:=2;
	tmp:=(a[1]+a[n])/len;
	ans:=tmp;
	i:=2;j:=n-1;
	repeat
		if a[i]<a[j] then begin
			tmp:=(tmp*len+a[i])/(len+1);
                        inc(i);
		end else begin
			tmp:=(tmp*len+a[j])/(len+1);
                        dec(j);
		end;
		inc(len);
		if ans>tmp then begin
                        ans:=tmp;
                end;
	until i>j;
	end;
	writeln(ans:0:3);
end.

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
	writeln(ans:0:3);
end.

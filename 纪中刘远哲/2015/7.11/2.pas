const	maxm=10000000;maxq=1000;mo=2147483647;
var	a,b:array[1..maxq] of int64;
	{p:array[1..maxm] of boolean;}
	sum:array[0..maxm] of longint;
	pp:array[1..1000] of boolean;
	q,tot,i:longint;
	m:int64;
procedure init;
var	k1,k2,k3,k4,i:longint;
	t:int64;
begin
	readln(q,a[1],b[1],k1,k2,k3,k4,M);
	for i:=2 to q do begin			//mod mo
		a[i]:=(int64(a[i-1])*k1+k2) mod 11111123111111;
		b[i]:=(int64(b[i-1])*k3+k4) mod 11111123111111;
	end;
	for i:=1 to q do begin
		a[i]:=a[i] mod M+1;
		b[i]:=b[i] mod M+1;
		if a[i]>b[i] then
		begin
			t:=a[i];
			a[i]:=b[i];
			b[i]:=t;
		end;
	end;
end;
procedure prepar;
var	i,j,tot1,tmp,ii:longint;
begin
	tot:=1;sum[1]:=0;
	{p[tot]:=false;}
	i:=0;
	while tot<maxm do begin
		inc(i);
		tot1:=0;ii:=i;
		while ii<>0 do begin
			tmp:=ii mod 2;
			inc(tot1);
			if tmp=1 then pp[tot1]:=true else pp[tot1]:=false;
			ii:=ii>>1;
		end;
		for j:=1 to tot1 do begin
			if tot=maxm then break;
			inc(tot);
			if pp[tot1] then sum[tot]:=sum[tot-1]+1
			else sum[tot]:=sum[tot-1];
			dec(tot1);
		end;
	end;
	{
	for i:=1 to maxm do begin
		if p[i] then
			sum[i]:=sum[i-1]+1
		else
			sum[i]:=sum[i-1];
	end;}
end;
procedure work;
var	i,tmp:longint;
	ans,x:int64;
begin
	x:=1;ans:=0;
	for i:=1 to q do begin
		tmp:=sum[b[i]]-sum[a[i]-1];
		ans:=(ans+tmp*x) mod mo;
		x:=(x*7) mod mo;
	end;
	writeln(ans);
end;
begin
	assign(input,'digit.in');reset(input);
	assign(output,'digit.out');rewrite(output);

	prepar;
	init;
	//for i:=1 to maxm do writeln(sum[i]);
	work;

	//close(input);close(output);
end.

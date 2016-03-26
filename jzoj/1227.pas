const	maxp=100000;maxn=100000;mo=1 shl 17-1;
var	i,j,m,n,t:longint;
	pri,sp,sp1:array[0..maxp] of int64;
	flag:array[1..maxn] of boolean;
	a:array[0..maxp] of longint;
	b,d:array[1..maxn] of int64;
	c:array[1..maxn] of longint;
	ans:int64;
{procedure fj(x:longint);
var	i:longint;
begin
	
	while (x<>1) and (i<=pri[0]) do begin
		while x mod pri[i]=0 do begin
			if not flag[i] then begin
				flag[i]:=true;
				inc(a[0]);
				a[a[0]]:=pri[i];
			end;
			x:=x div pri[i];
		end;
		inc(i);
	end;
	if x<>1 then begin
		inc(a[0]);
		a[a[0]]:=x;
	end;
end;}
function half(m:longint):longint;
var	mid,l,r:longint;
begin
	l:=1;r:=pri[0];
	while l<=r do begin
		mid:=(l+r)>>1;
		if m<pri[mid] then r:=mid-1 else l:=mid+1; 
		if m=pri[mid] then exit(mid);
	end;
	exit(r);
end;
function ksm(x,y:int64):int64;
begin
	ksm:=1;
	while y<>0 do begin
		if y mod 2=1 then ksm:=(ksm*x) mod mo;
		x:=(x*x) mod mo;
		y:=y>>1;
	end;
end;
procedure work;
var	j:longint;
begin
	{fillchar(flag,sizeof(flag),false);
	fillchar(a,sizeof(a),0);}
	j:=c[m];
	ans:=b[n];
	ans:=(ans*sp1[j]) mod mo;
	ans:=(ans*d[j]) mod mo;
	//ans:=(ans*sp1[j]) mod mo*ksm(sp[j],mo-2) mod mo;
end;
procedure prepar;
var	i,j:longint;
begin
	fillchar(flag,sizeof(flag),true);
	i:=2;
	while (i<=maxn) do begin
		inc(pri[0]);
		pri[pri[0]]:=i;
		j:=2;
		while (i*j<=maxn) do begin
			flag[i*j]:=false;
			inc(j);
		end;
		inc(i);
		while not flag[i] do inc(i);
	end;
	b[1]:=1;sp[1]:=2;sp1[1]:=1;j:=1;d[1]:=ksm(sp[1],mo-2);
	for i:=2 to maxn do begin
		b[i]:=(b[i-1]*i) mod mo;
		if pri[j+1]<=i then inc(j);
		c[i]:=j;
	end;
	for i:=2 to pri[0] do begin
		sp[i]:=(sp[i-1]*pri[i]) mod mo;
		sp1[i]:=(sp1[i-1]*(pri[i]-1)) mod mo;
		d[i]:=ksm(sp[i],mo-2) mod mo;
	end;
end;
begin
	//assign(input,'1227.in');reset(input);
	//assign(output,'.out');rewrite(output);

	prepar;
	readln(t);
	for i:=1 to t do begin
		readln(n,m);
		work;
		writeln(ans mod mo);
	end;
end.


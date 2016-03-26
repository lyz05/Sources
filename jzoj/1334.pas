uses	math;
const	maxn=100000;maxm=100000;
var	i,j,k,m,n,ans:longint;
	a,f:array[0..maxn] of longint;
	b:array[0..maxn] of boolean;
	p:array[1..maxm] of longint;
	pri:array[0..70] of longint;
procedure prepar;
var	i,j:longint;
begin
	fillchar(b,sizeof(b),1);
	for i:=2 to trunc(sqrt(maxm)) do 
		if b[i] then begin
			inc(pri[0]);
			pri[pri[0]]:=i;
			for j:=i to maxm div i do 
				b[i*j]:=false;
		end;
end;
procedure fj(x,id:longint);
var	i:longint;
begin
	//fillchar(b,sizeof(b),0);
	i:=1;
	while (x<>1) and (i<=pri[0]+1) do begin
		if (i=pri[0]+1) then begin
			pri[pri[0]+1]:=x;
		end;
		if x mod pri[i]=0 then begin
			//if (not b[p[pri[i]]]) or (p[pri[i]]=0) then begin
			//	b[p[pri[i]]]:=true;
				f[id]:=max(f[id],f[p[pri[i]]]+1);
				p[pri[i]]:=id;
			//end;
		end;
		while x mod pri[i]=0 do x:=x div pri[i];
		inc(i);
	end;
end;
begin
	assign(input,'1334.in');reset(input);
	//assign(output,'.out');rewrite(output);

	prepar;
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
		f[i]:=1;
		fj(a[i],i);
	end;
	ans:=0;
	for i:=1 to n do ans:=max(ans,f[i]);
	writeln(ans);
end.

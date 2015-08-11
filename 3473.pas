const	maxn=100+5;maxm=10+5;mo=1000000007;len=17;size=(1 shl 5);jw=100000000000000000;
type	bignum=array[0..15] of int64;
	matrix=array[0..size,0..size] of int64;
var	i,j,m,n,tot,tmp:longint;
	st:array[0..(1 shl maxm),0..1] of longint;
	dp:array[0..maxn,0..(1 shl maxm)] of int64;
	s,nn,mm:string;						//change
	base,ans:matrix;
	n1:bignum;
	sum:int64;
procedure dfs(n,from,next:longint);
begin
	if (n>m) then begin
		exit;
	end;
	if (n=m) then begin
		st[tot][0]:=from;
		st[tot][1]:=next;
		inc(tot);
		exit;
	end;
	dfs(n+2,(from<<2)+3,(next<<2)+3);
	dfs(n+1,(from<<1)+1,(next<<1));
	dfs(n+1,(from<<1),(next<<1)+1);
end;
procedure div2(var x:bignum);
var	i,t:longint;
begin
	t:=0;
	//if odd(x[1]) then dec(x[1]);//dec
	for i:=x[0] downto 1 do begin
		x[i]:=t*jw+x[i];
		t:=x[i] mod 2;
		x[i]:=x[i] div 2;
		if x[i]=0 then x[0]:=i-1;
	end;
end;
procedure stom(var s:string;var num:bignum);			//change
var	ts:string[len];
	i:longint;
begin
	fillchar(num,sizeof(num),0);
	ts:='';
	for i:=length(s) downto 1 do begin
		ts:=s[i]+ts;
		if length(ts)=len then begin
			inc(num[0]);
			val(ts,num[num[0]]);
			ts:='';
		end;
	end;
	if ts<>'' then begin
		inc(num[0]);
		val(ts,num[num[0]]);
	end;
end;
function mul(x,y:matrix):matrix;
var     i,j,k,size1:integer;
	z:matrix;
begin
	size1:=(1<<m);
        fillchar(z,sizeof(z),0);
        for i:=0 to size1 do
        for j:=0 to size1 do
	for k:=0 to size1 do begin
		z[i,j]:=(z[i,j]+x[i,k]*y[k,j])mod mo;
	end;
	exit(z);
end;
procedure work(y:bignum);
begin
	fillchar(ans,sizeof(ans),0);
	for i:=0 to (1<<m) do ans[i][i]:=1;
	while (y[0]<>0) do begin
		if odd(y[1]) then begin
			ans:=mul(ans,base);
		end;
		base:=mul(base,base);
		div2(y);
	end;
end;
begin
	readln(s);
	tmp:=pos(' ',s);
	nn:=copy(s,1,tmp-1);
	mm:=copy(s,tmp + 1,length(s) - tmp);val(mm,m);

	tot:=0;
	dfs(0,0,0);{
	if (length(nn)<=2) or (nn='100') then begin
		val(nn,n);
		if odd(n*m) then begin
			writeln(0);
			exit;
		end;	

		dp[0][(1<<m)-1]:=1;
		for i:=1 to n do 
			for j:=0 to tot-1 do begin
				dp[i][st[j][1]]:=(dp[i][st[j][1]]+dp[i-1][st[j][0]]) mod mo;
			end;
		writeln(dp[n][(1<<m)-1]);
	end else begin}
		fillchar(base,sizeof(base),0);
		for j:=0 to tot-1 do begin
			base[st[j][0]][st[j][1]]:=1;
		end;
		stom(nn,n1);
		work(n1);
		sum:=ans[(1<<m)-1][(1<<m)-1];
		writeln(sum mod mo);
	//end;
end.

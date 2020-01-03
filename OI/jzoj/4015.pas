const	oo=1000000;maxm=1000000000;
var	m,n,x0,a,b,c:longint;
	hash:array[1..oo] of longint;
	ans:array[1..oo] of longint;
procedure work1;
var	x:int64;
	i,id,tmp:longint;
begin
	id:=0;
	x:=x0 mod m;
	for i:=1 to n do begin
		x:=(a mod m*x mod m*x
			mod m+b mod m*x mod m+c) mod m;
		if m<=oo then begin
		ans[i]:=x;
		if hash[x]=0 then hash[x]:=i else begin
			id:=hash[x];
			break;
		end;
		end;
		//writeln(x);
	end;
	if id=0 then writeln(x) else begin
		tmp:=(n-id+1) mod (i-id);
		if tmp=0 then writeln(ans[i-1]) else writeln(ans[id+tmp-1]);
	end;
end;
function ksm(ds,cs,mo:int64):int64;
var	re:int64;
begin
	if cs=1 then exit(ds mod mo);
	re:=ksm(ds,cs div 2,mo);
	if cs mod 2=0 then exit((re*re) mod mo) else 
		exit((re*re) mod mo*ds mod mo);
end;
procedure work2;
var	zs,ans1,ans2:int64;
begin
	if m=1 then writeln(0) else begin
		zs:=ksm(2,n,m-1);
		ans2:=ksm(x0+b div 2 div a,zs,m);
		if zs=0 then zs:=m-1 else zs:=zs-1;
		ans1:=ksm(a,zs,m);
		ans1:=ans1*ans2 mod m;
		ans1:=(ans1+m-(b div 2 div a)mod m) mod m;
	end;
	writeln(ans1);
end;
begin
	assign(input,'4015.in');reset(input);
	assign(output,'4015.out');rewrite(output);

	readln(x0,a,b,c,n,m);
	if ((n<=oo) and (m<=maxm)) or ((n<=maxm) and (m<=oo)) then 
		work1 else work2;


	close(input);close(output);
end.

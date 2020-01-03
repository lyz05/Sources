var	i,j,k,m,n:longint;
	a,b,c,d,ans,minn,tmp,x:int64;
function ksm(x,y:int64):int64;
var	i:longint;
begin
	ksm:=1;
	while y<>0 do begin
		if odd(y) then ksm:=(ksm*x) mod d;
		x:=(x*x) mod d;
		y:=y>>1;
	end;
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'1.out');rewrite(output);

	ans:=1;
	readln(n,m);
	for i:=1 to n do begin
		readln(a,b,c,d);
		x:=ans;minn:=1<<62;
		while x<=m do begin
			tmp:=(a*ksm(b,x)+c) mod d;
			if tmp<minn then begin
				minn:=tmp;
				ans:=x;
			end;
			inc(x);
		end;
		writeln(ans);
	end;
end.

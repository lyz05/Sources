const	maxn=40000+5;
var	a:array[1..maxn,1..maxn] of boolean;
	i,j,k,m,n,x,y,xx,yy,ans:longint;
        //lans:longint;
procedure jl(x1,y1,x2,y2:longint;var x,y:longint);
begin
	x:=abs(x1-x2);
	y:=abs(y1-y2);
end;
begin
	//assign(input,'.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
        //for n:=1 to 100 do begin
        //write(n,' ');


        for i:=1 to n do
		for j:=1 to n do
			a[i,j]:=true;
        a[1,1]:=false;
        ans:=n*n-1;
	for i:=1 to n do
		for j:=1 to n do begin
			if a[i,j]=true then begin
				jl(1,1,i,j,x,y);
				k:=1;
				xx:=i+x*k;yy:=j+y*k;
				while (xx<=n) and (yy<=n) do begin
                                        dec(ans);
                                        a[xx,yy]:=false;
					inc(k);
					xx:=i+x*k;yy:=j+y*k;
				end;
			end;
		end;
	writeln(ans);

        //lans:=ans;
        //end;
	//close(input);close(output);
end.


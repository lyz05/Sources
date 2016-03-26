const name='shoberu';
	 maxn=100000000;
var	n,m,i,j,k,t,x:longint;
	xx:array[1..maxn] of qword;
	p:array[1..maxn] of boolean;
	ans:qword;
procedure gcdd(x:longint);
var i,t,y:longint;
begin
	for i:=1 to x do p[i]:=true;
	//fillchar(p,sizeof(p),true);
	for i:=2 to trunc(sqrt(x)) do begin
		if x mod i=0 then begin
			t:=1;
			y:=i;
			while (y*t)<=x do begin
				p[y*t]:=false;
				inc(t);
			end;
			t:=1;
			y:=x div i;
			while (y*t)<=x do begin
				p[y*t]:=false;
				inc(t);
			end;
		end;
	end;
        if x<>1 then p[x]:=false;
end;
function solve(x:longint):qword;
var	i,y:longint;
	tmp:qword;
begin
	if xx[x]<>0 then exit(xx[x]);
	tmp:=0;
        gcdd(x);
	for y:=1 to x do
		if p[y] then inc(tmp,y);
	{for y:=1 to x do begin
		if gcd(x,y)=1 then inc(tmp,y);
	end;}
	xx[x]:=tmp;
	exit(xx[x]);
	//exit(tmp);

end;
begin
	//assign(input,name+'.in');reset(input);
        //assign(output,name+'.out');rewrite(output);

	for x:=1 to 10000 do solve(x);

        //t:=1;
	readln(t);
	for i:=1 to t do begin
	          read(n);
            //for n:=1 to 1000 do begin
		ans:=0;
		for j:=1 to trunc(sqrt(n)) do begin
			if n mod j=0 then begin
				x:=j;
				inc(ans,solve(x));
				x:=n div j;
                    if j<>x then
				        inc(ans,solve(x));
			end;
		end;
		writeln(ans);
            //end;
	end;

	//close(input);close(output);
end.


input
20
52
3
52
65
15
25
36
25
14
25
36
25
36
45
25
10
2
3
52
566

output
1
2
4
6
11
11
22
22
31
32

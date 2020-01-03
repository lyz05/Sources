const	mo=998244353;ws = 100000000000000000;yw=17;
type	arr=array[1..2,1..2] of int64;
	arr1=array[0..10000+5] of int64;
var	a,tmp:arr;
	ans:array[0..2] of int64;
	n:arr1;
	s:ansistring;
	i,j:longint;
function mul(x,y:arr):arr;
var     i,j,k:integer;
begin
        fillchar(mul,sizeof(mul),0);
        for i:=1 to 2 do
        for j:=1 to 2 do
                if x[i,j]<>0 then begin
                        for k:=1 to 2 do begin
                                if y[j,k]<>0 then mul[i,k]:=(mul[i,k]+x[i,j]*y[j,k])mod mo;
                        end;
                end;
end;
function inc(a:arr1):arr1;
var	i:longint;
begin
	a[1]:=a[1]+1;
	for i:=2 to a[0]+1 do begin
		if a[i-1]<ws then break;
		a[i]:=a[i]+a[i-1] div ws;
		a[i-1]:=a[i-1] mod ws;
	end;
	if a[a[0]+1]>0 then a[0]:=a[0]+1;
	exit(a);
end;
function dec(a:arr1):arr1;
var	i:longint;
begin
	a[1]:=a[1]-1;
	for i:=2 to a[0] do begin
		if a[i-1]<0 then begin
			a[i-1]:=a[i-1]+ws;
			a[i]:=a[i]-1;
		end else break;
	end;
	if a[a[0]]=0 then a[0]:=a[0]-1;
	exit(a);
end;
function div2(ans:arr1):arr1;
var	i:longint;
begin
	for i:=ans[0] downto 2 do begin
		ans[i-1]:=ans[i-1]+(ans[i] mod 2)*ws;
		ans[i]:=ans[i]>>1;
	end;
	ans[1]:=ans[1]>>1;
	if ans[ans[0]]=0  then ans[0]:=ans[0]-1;
	div2:=ans;
end;
function matrix(x:arr1):arr;
begin
	fillchar(matrix,sizeof(matrix),0);
	matrix[1,1]:=1;matrix[2,2]:=1;
	a[1,1]:=1;a[1,2]:=1;a[2,1]:=1;a[2,2]:=0;
	while (x[0]<>0) do begin
		if odd(x[1]) then matrix:=mul(matrix,a);
		a:=mul(a,a);
		x:=div2(x);
	end;
end;
procedure getfibo(x:arr1);
begin
	if (x[0]=1) and (x[1]<=1) then exit else begin
		tmp:=matrix(dec(x));
		ans[1]:=(tmp[1,2]+tmp[2,2]) mod mo;ans[2]:=(tmp[1,1]+tmp[2,1])mod mo;
	end;
end;
begin
	//assign(input,'number.in');reset(input);	
	//assign(output,'number.out');rewrite(output);


	readln(s);
	n[0]:=length(s);
	for i:=length(s) downto 1 do begin
		if i mod yw = 0 then j:=i div yw else j:=i div yw+1;
		n[j]:=n[j]*10+ord(s[n[0]-i+1])-ord('0');
	end;
	if n[0] mod yw = 0 then n[0]:=n[0] div yw else n[0]:=n[0] div yw+1;

	ans[1]:=1;ans[2]:=1;
	if (n[0]=1) and (n[1]=1) then ans[0]:=2 else begin
		getfibo(inc(n));
		ans[0] := (ans[1]*ans[2]) mod mo;
	end;
	writeln(ans[0]);

	//close(input);close(output);
end.

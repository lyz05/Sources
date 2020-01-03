const	mo=998244353;
type	arr=array[1..2,1..2] of int64;
var	a,tmp:arr;
	ans:array[0..2] of int64;
        n:qword;
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
function matrix(x:qword):arr;
begin
	fillchar(matrix,sizeof(matrix),0);
	matrix[1,1]:=1;matrix[2,2]:=1;
	a[1,1]:=1;a[1,2]:=1;a[2,1]:=1;a[2,2]:=0;
	while (x<>0) do begin
		if odd(x) then matrix:=mul(matrix,a);
		a:=mul(a,a);
		x:=x shr 1;
	end;
end;
function getfibo(x:qword):int64;
begin
	if x<=1 then exit(1) else begin
		tmp:=matrix(x-1);
		exit((tmp[1,1]+tmp[2,1])mod mo);
	end;
end;
begin
	//assign(input,'number.in');reset(input);
	//assign(output,'number.out');rewrite(output);

	readln(n);
	ans[1] := getfibo(n);ans[2] := getfibo(n+1);
	ans[0] := (ans[1]*ans[2]) mod mo;
	writeln(ans[0]);
	//close(input);close(output);
end.

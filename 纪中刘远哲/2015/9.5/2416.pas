const   name='new';
        //maxn=1000000000;
        mo=9223372036854775800;
type	arr=array[1..2,1..2] of int64;
var	i,j,k,t,x,y:longint;
	a,ans:arr;
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
        if x=1 then exit(a)
        else begin
                matrix:=matrix(x shr 1);
                matrix:=mul(matrix,matrix);
                if odd(x) then matrix:=mul(matrix,a);
        end;
end;
begin
	//assign(input,name+'.in');reset(input);
	//assign(output,name+'.out');rewrite(output);

        a[1,1]:=1;a[1,2]:=1;a[2,1]:=1;a[2,2]:=0;
	readln(n);
        if n=1 then writeln(1) else begin
                ans:=matrix(n-1);
                writeln(ans[1,1] mod mo);
        end;
	//close(input);close(output);
end.

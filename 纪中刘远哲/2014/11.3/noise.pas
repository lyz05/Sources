const   maxm=100+5;
var	i,j,k,m,n,x,t,ans,max,kk:longint;
	a:array[1..maxm] of longint;
function solve(x,k:longint):longint;
var i,j,t,kk:longint;
begin
        kk:=k;
        solve:=0;
	inc(k);
	j:=a[x] div k;
        if a[x] mod k>k div 2 then inc(j);
        t:=0;
        for i:=1 to a[x] do begin
                inc(t);
                if (t>j) and (kk>0) then begin
                        t:=1;
                        dec(kk);
                end;
                inc(solve,t);
        end;
end;
procedure print(s:longint);
begin
	writeln(s);
	halt;
end;
begin
	assign(input,'noise.in');reset(input);
	assign(output,'noise.out');rewrite(output);

	readln(n,m,k);
	for i:=1 to n do begin
		readln(x);
                inc(a[x]);
	end;
	if m=1 then print(solve(1,k));
        ans:=0;
        max:=0;
        for i:=1 to m do begin
               if a[i]>max then begin
                        max:=a[i];
                        kk:=i;
               end;
        end;
        t:=k div m;
        inc(ans,solve(kk,t+k mod m));
        for i:=1 to m do begin
                if i<>kk then
                        inc(ans,solve(i,t));
        end;
        print(ans);

	close(input);close(output);
end.


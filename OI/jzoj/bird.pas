var
        f:array[0..10001,0..1001] of longint;
        l,r,x,y:array[0..10001] of longint;
        n,m,kk,i,j,k,o,i1,x1,ans:longint;
        p:boolean;
function min(a,b:longint):longint;
begin
        if a<b then exit(a);
        exit(b);
end;
begin
        //assign(input,'bird.in');reset(input);
        readln(n,m,kk);
        for i:=1 to n do begin
                readln(x[i],y[i]);
                r[i]:=m+1;
                for j:=1 to m do f[i,j]:=maxlongint;
        end;
        for i:=1 to kk do begin
                read(x1);
                readln(l[x1],r[x1]);
        end;

        for i:=1 to m do begin
                if i>y[1] then f[1,i-y[1]]:=0;
                for j:=1 to ((m-i) div x[1]) do begin
                        k:=i+j*x[1];
                        f[1,k]:=min(f[1,k],j);
                end;
                f[1,m]:=min(f[1,m],((m-j) div x[1])+1);
        end;
        for i:=1 to n-1 do begin
                i1:=i+1;
                for j:=l[i]+1 to r[i]-1 do
		    if f[i,j]<>maxlongint then begin
                        if j>y[i1] then f[i1,j-y[i1]]:=f[i,j];
                        for k:=1 to ((m-j) div x[i1]) do begin
                                o:=j+k*x[i1];
                                f[i1,o]:=min(f[i1,o],f[i,j]+k);
                        end;
                        f[i1,m]:=min(f[i1,m],f[i,j]+((m-j) div x[i1])+1);
                    end;
        end;
        ans:=maxlongint;
        for i:=l[n]+1 to r[n]-1 do 
		if f[n,i]<ans then ans:=f[n,i];
        if ans=maxlongint then begin
                writeln(0);
                ans:=0;
                if (l[n]<>0) or (r[n]<>m+1) then inc(ans);
                for i:=n-1 downto 1 do begin
                        if (l[i]<>0) or (r[i]<>m+1) then inc(ans);
                        p:=false;
                        for j:=1 to l[i] do if f[i,j]<>maxlongint then begin
                                p:=true;
                                break;
                        end;
                        if p then break;
                        for j:=r[i] to m do if f[i,j]<>maxlongint then begin
                                p:=true;
                                break;
                        end;
                        if p then break;
                end;
                writeln(kk-ans);
        end else begin
                writeln(1);
                writeln(ans);
        end;
        //close(input);
        //close(output);
end.

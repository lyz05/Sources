type
        lzx=record
                y,next:longint;
        end;

const
        p=10007;

var
        sum,max,w,g,sumx,m1,m2:array[1..200000] of int64;
        e:array[1..400000] of lzx;
        i,j,n,tot,x,y:longint;
        ans,ansn:int64;

procedure add(x,y:longint);
begin
        inc(tot);
        e[tot].y:=y;
        e[tot].next:=g[x];
        g[x]:=tot;
end;

procedure ss(x:longint);
var     i,j:longint;
begin
        i:=g[x];
        while i<>0 do begin
                j:=e[i].y;
                sum[x]:=sum[x]+w[j];
                if w[j]>m1[x] then begin
                        m2[x]:=m1[x];
                        m1[x]:=w[j];
                end
                else if w[j]>m2[x] then m2[x]:=w[j];
                i:=e[i].next;
        end;
        i:=g[x];
        max[x]:=m1[x]*m2[x];
        while i<>0 do begin
                j:=e[i].y;
                sumx[x]:=sumx[x]+(sum[x]-w[j])*w[j];
                i:=e[i].next;
        end;
end;

begin
        assign(input,'link.in');reset(input);
        assign(output,'link.out');rewrite(output);
        readln(n);
        for i:=1 to n-1 do begin
                readln(x,y);
                add(x,y);
                add(y,x);
        end;
        for i:=1 to n do read(w[i]);
        for i:=1 to n do ss(i);
        for i:=1 to n do begin
                ans:=(ans+sumx[i]) mod p;
                if max[i]>ansn then ansn:=max[i];
        end;
        writeln(ansn,' ',ans);
        close(input);close(output);
end.
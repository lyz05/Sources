var
        la,go:array[0..100001] of longint;
        len:array[0..100001] of extended;
        g,aa,d:array[0..680] of longint;
        q:array[0..1000001] of longint;
        p:array[0..1000001] of boolean;
        dis:array[0..680] of extended;
        a1:array[0..680] of boolean;
        l,r,mid,ml,ml1:extended;
        n,t,t1,a,b,i:longint;
        s:ansistring;
        pp:boolean;
function get(s:string):longint;
begin
        exit((ord(s[1])-97)*26+(ord(s[2])-96));
end;
procedure insert(a,b:longint; l:extended);
begin
        inc(t);
        la[t]:=g[a];
        len[t]:=l;
        go[t]:=b;
        g[a]:=t;
end;
procedure spfa(st,i:longint; dl:extended);
var
        j:longint;
begin
        j:=g[i];
        while j<>0 do begin
                if dis[i]+(len[j]-dl)>dis[go[j]] then begin
                        dis[go[j]]:=dis[i]+(len[j]-dl);
                        if dis[go[j]]>ml1 then begin
                                pp:=true;
                                exit;
                        end;
                        if not p[go[j]] then begin
                                p[go[j]]:=true;
                                spfa(st,go[j],dl);
                                if pp then exit;
                        end;
                        if go[j]=st then begin
                                pp:=true;
                                exit;
                        end;
                end;
                j:=la[j];
        end;
        p[i]:=false;
end;
function ok(l:extended):boolean;
var
        i,j:longint;
begin
        pp:=false;
        ml1:=(ml-l)*t1;
        for i:=1 to t1 do begin
                for j:=1 to t1 do begin
                        d[aa[j]]:=0;
                        dis[aa[j]]:=0;
                        p[aa[j]]:=false;
                end;
                p[aa[i]]:=true;
                spfa(aa[i],aa[i],l);
                if pp then exit(true);
        end;
        exit(false);
end;
begin
        readln(n);
        for i:=1 to n do begin
                readln(s);
                if r<length(s) then r:=length(s);
                if length(s)=1 then continue;
                a:=get(copy(s,1,2));
                b:=get(copy(s,length(s)-1,2));
                a1[a]:=true;
                insert(a,b,length(s));
        end;
        for i:=1 to 676 do begin
                if a1[i] then begin
                        inc(t1);
                        aa[t1]:=i;
                end;
        end;
        l:=1;
        ml:=r;
        while r-l>=1e-4 do begin
                mid:=(l+r)/2;
                if ok(mid) then l:=mid
                else r:=mid;
        end;
        if l<2 then writeln('No solution.')
        else writeln(l:0:2);
end.

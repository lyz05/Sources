uses math;
var
        tree:array[0..400000] of longint;
        s:array[0..100000,1..2] of longint;
        h,p,v:array[0..100000] of longint;
        next,go:array[0..500000] of longint;
        i,j,k,l,t,n,m,tot,top,ans:longint;
procedure add(x,y:longint);
begin
        inc(tot);
        go[tot]:=y;
        next[tot]:=h[x];
        h[x]:=tot;
end;
procedure change(p,l,r,a,b:longint);
var
        mid:longint;
begin
        if l=r then
        begin
                if b>tree[p] then tree[p]:=b;
                exit;
        end;
        mid:=(l+r) div 2;
        if a<=mid then change(p*2,l,mid,a,b) else change(p*2+1,mid+1,r,a,b);
        tree[p]:=max(tree[p*2],tree[p*2+1]);
end;
function get(p,l,r,a,b:longint):longint;
var
        mid:longint;
begin
        if a>b then exit(0);
        if (l=a)and(r=b) then exit(tree[p]);
        mid:=(l+r) div 2;
        if b<=mid then exit(get(p*2,l,mid,a,b))
        else if a>mid then exit(get(p*2+1,mid+1,r,a,b))
        else exit(max(get(p*2,l,mid,a,mid),get(p*2+1,mid+1,r,mid+1,b)));
end;
begin
	assign(input,'4006.in');reset(input);
	//assign(output,'.out');rewrite(output);

        readln(n,m);
        for i:=1 to m do
        begin
                readln(j,k);
                add(j,k);
        end;
        for i:=1 to n do
                read(p[i]);
        for i:=1 to n do
                read(v[i]);
        ans:=0;
        for i:=1 to n do
        begin
                top:=0;
                t:=h[i];
                while t<>0 do
                begin
                        l:=get(1,1,n,1,go[t]-1)+p[go[t]]+v[i];
                        if l>ans then ans:=l;
                        inc(top);
                        s[top,1]:=go[t];
                        s[top,2]:=l;
                        t:=next[t];
                end;
                while top>0 do
                begin
                        change(1,1,n,s[top,1],s[top,2]);
                        dec(top);
                end;
        end;
        writeln(ans);
end.

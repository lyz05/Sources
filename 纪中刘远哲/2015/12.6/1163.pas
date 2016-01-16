type
    lzx=record
        x,data,next:longint;
    end;

var
    heap:array[0..4000000] of lzx;
    e:array[-100001..100001] of lzx;
    g,ng,dis,q:array[0..10001] of longint;
    p:array[0..10001] of boolean;
    n,m,k,i,j,x,y,z,tot,ans:longint;

procedure add(x,y,z:longint);
begin
    inc(tot);
    e[tot].x:=y;
    e[tot].data:=z;
    e[tot].next:=g[x];
    g[x]:=tot;
    e[-tot].x:=x;
    e[-tot].data:=z;
    e[-tot].next:=ng[y];
    ng[y]:=-tot;
end;

procedure spfa;
var     i,j,z,x,y,l,r:longint;
begin
    fillchar(dis,sizeof(dis),$7f);
    dis[n]:=0;
    l:=0;
    r:=1;
    q[1]:=n;
    p[n]:=true;
    while l<>r do begin
        l:=l mod 10001+1;
        x:=q[l];
        i:=ng[x];
        while i<>0 do begin
            y:=e[i].x;
            if dis[y]>dis[x]+e[i].data then begin
                dis[y]:=dis[x]+e[i].data;
                if not p[y] then begin
                    p[y]:=true;
                    r:=r mod 10001+1;
                    q[r]:=y;
                end;
            end;
            i:=e[i].next;
        end;
        p[x]:=false;
    end;
end;

procedure swap(var a,b:lzx);
var     t:lzx;
begin
    t:=a;a:=b;b:=t;
end;

procedure up(x:longint);
begin
    if x=1 then exit;
    if heap[x].data<heap[x shr 1].data then begin
        swap(heap[x],heap[x shr 1]);
        up(x shr 1);
    end;
end;

procedure ins(x,y,z:longint);
var i:longint;
begin
    inc(tot);
    heap[tot].x:=x;
    heap[tot].data:=y;
    heap[tot].next:=z;
    up(tot);
end;

procedure down(x:longint);
var     i:longint;
begin
        if 2*x>tot then exit;
        i:=2*x;
        if (i+1<=tot) and (heap[i+1].data<heap[i].data) then inc(i);
        if heap[x].data>heap[i].data then begin
                swap(heap[x],heap[i]);
                down(i);
        end;
end;

procedure del;
begin
    swap(heap[1],heap[tot]);
    dec(tot);
    down(1);
end;

begin
	assign(input,'1163.in');reset(input);
    readln(n,m,k);
    for i:=1 to m do begin
        read(x,y,z);
                readln;
        add(x,y,z);
    end;
    spfa;
    tot:=0;
    ins(0,dis[1],1);
    ans:=-1;
    while k>0 do begin
        if (heap[1].next=n) and (heap[1].x<>ans) then begin
            ans:=heap[1].x;
            dec(k);
            if k=0 then break;
        end;
        i:=g[heap[1].next];
        while i<>0 do begin
            y:=e[i].x;
            ins(heap[1].x+e[i].data,heap[1].x+e[i].data+dis[y],y);
            i:=e[i].next;
        end;
        del;
    end;
    writeln(ans);
end.

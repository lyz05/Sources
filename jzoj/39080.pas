Const
        Maxn=100005;
Var
        a: array[0..maxn,0..2]of Longint;
        n,m,i,k: Longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2][1];
         repeat
           while a[i][1]<x do
            inc(i);
           while x<a[j][1] do
            dec(j);
           if not(i>j) then
             begin
                a[0]:=a[i];
                a[i]:=a[j];
                a[j]:=a[0];
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
Procedure find(l,r,w: Longint);
Var
        ll,rr,tmp,mid,wz: Longint;
Begin
        if (l=r)or(w=0) Then Begin
                Writeln(a[l][2]);
                exit;
        End;
        if (a[l][1] And (1<<(w-1)))=(a[r][1]And(1<<(w-1))) Then Begin
                find(l,r,w-1);
                exit;
        End;
        if k And (1<<(w-1))>0 Then tmp:=1 Else tmp:=0;
        ll:=l;
        rr:=r;
        wz:=0;
        While ll<=rr Do Begin
                mid:=(ll+rr) Div 2;
                if a[mid][1] and(1<<(w-1))>0 Then BEgin
                        wz:=mid;
                        rr:=mid-1;
                End Else ll:=mid+1;
        End;
        if tmp=1 Then r:=wz-1 Else l:=wz;
        find(l,r,w-1);
End;
Begin
        Readln(n,m);
        For i:=1 To n Do Begin
                Read(a[i][1]);
                a[i][2]:=i;
        End;
        sort(1,n);
        For i:=1 To m Do Begin
                Read(k);
                find(1,n,32);
        End;
End.

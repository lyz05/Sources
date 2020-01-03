{const fk[1..7,1..4,1..4,1..4] of integer=(((),(),(),(),),

                                          (),
                                          (),
                                          (),
                                          (),
                                          (),
                                          (),)  }
var c,p,i,j,tmp,ans:longint;
    a:array[0..101] of integer;
begin
  readln(c,p);
  for i:=1 to c do read(a[i]);

  ans:=0;
  case p of
    1:begin
        inc(ans,c);
        for i:=1 to c-3 do
        begin
          if (a[i]=a[i+1]) and (a[i+2]=a[i+3]) and (a[i+1]=a[i+2]) then
            inc(ans);
         end;
      end;
    2:begin
        for i:=1 to c-1 do
        begin
          if (a[i]=a[i+1]) then inc(ans);
        end;
      end;
    3:begin
        for i:=1 to c-2 do
          if (a[i+2]=a[i+1]+1) and (a[i]=a[i+1]) then inc(ans);
        for i:=1 to c-1 do
          if a[i]=a[i+1]+1 then inc(ans);
      end;
    4:begin
         for i:=1 to c-2 do
          if (a[i]=a[i+1]+1) and (a[i+2]=a[i+1]) then inc(ans);
         for i:=1 to c-1 do
          if a[i+1]=a[i]+1 then inc(ans);
      end;
    5:begin
        for i:=1 to c-1 do
        begin
         if (a[i]=a[i+1]+1) then inc(ans);
         if (a[i+1]=a[i]+1) then inc(ans);
        end;
        for i:=1 to c-2 do
        begin
          if (a[i]=a[i+2]) and (a[i]=a[i+1]) then inc(ans);
          if (a[i+1]+1=a[i]) and (a[i]=a[i+2]) then inc(ans);
        end;
      end;
    6:begin
        for i:=1 to c-1 do
        begin
         if (a[i]=a[i+1]) then inc(ans);
         if (a[i+1]+2=a[i]) then inc(ans);
        end;
        for i:=1 to c-2 do
        begin
          if (a[i]=a[i+2]) and (a[i]=a[i+1]) then inc(ans);
          if (a[i+2]=a[i+1]) and (a[i]+1=a[i+1]) then inc(ans);
        end;
      end;
    7:begin
        for i:=1 to c-1 do
        begin
         if (a[i+1]=a[i]) then inc(ans);
         if (a[i]+2=a[i+1]) then inc(ans);
        end;
        for i:=1 to c-2 do
        begin
          if (a[i]=a[i+2]) and (a[i]=a[i+1]) then inc(ans);
          if (a[i]=a[i+1]) and (a[i+2]+1=a[i+1]) then inc(ans);
        end;
      end;
  end;
  writeln(ans);
end.

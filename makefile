#================================================================================
# Makefile
#================================================================================
CC=C:/MinGW/bin/g++.exe
AR=C:/MinGW/bin/ar.exe
LD=C:/MinGW/bin/g++.exe
FX=C:/Program\ Files\ \(x86\)/Microsoft\ DirectX\ SDK\ \(June\ 2010\)/Utilities/bin/x64/fxc.exe
FP=C:/MinGW/bin/g++.exe

PAD = dinput8 xinput
DRAW = d3d9 d3dx9_43 d3d11 d3dcompiler_47
CALL = dsound


CPPFLAGS := -Wall -Werror -std=c++2a -g  -DOPAL_DEBUG -DOPAL_HEAP -D_XM_NO_INTRINSICS_ -D_WIN32_WINNT=0x601 -DOPAL_DX11 -fno-exceptions -Wnoexcept -Wextra -Wformat=2 -Wcast-qual -Wcast-align -Wwrite-strings -Wfloat-equal -Wpointer-arith -Wno-missing-field-initializers -Wno-unused-parameter -Wno-multichar -Wno-unknown-pragmas -Wno-strict-aliasing
LDFLAGS  := 
FXFLAGS  := /nologo /Gfp /Ges

INCPATH := -iquote -I-  -I../../../Opal/Inc -I../../../Opal/Inc/Etc -I../../../Opal/Inc/Lib -I../../../Opal/Inc/Sys -I../../../Opal/Inc/Usr -IInc/ -ILib/ -I../../../Opal/Inc/Usr/Draw -I../../../Opal/Inc/Usr/Draw/prim -I../../../Opal/Inc/Usr/Draw/rsrc -I../../../Opal/Inc/Usr/Call -I../../../Opal/Inc/Usr/Call/prim -I../../../Opal/Inc/Usr/Call/rsrc -IC:/MinGW/include/ -IC:/MinGW/include/DirectX -IC:/MinGW/include/DirectX/TX -IC:/MinGW/include/DirectX/TK -IC:/MinGW/include/DirectX/Math -I../../../Opal/Inc/../Lib/Game -I../../../Opal/Inc/../Lib/Game/Scene -I../../../Opal/Inc/../Lib/Game/Actor -I../../../Opal/Inc/../Lib/Game/fsm -I../../../Opal/Inc/../Lib/Game/promoter -I../../../Opal/Inc/../Lib/Game/atari -I.
LIBRARY := -luuid -lole32 -lwinmm -ldxguid $(foreach lib,$(PAD),-l$(lib)) $(foreach lib,$(DRAW),-l$(lib)) $(foreach lib,$(CALL),-l$(lib)) -lstrmiids -ldxerr9 -lquartz -lWSock32 -limm32 -luser32 -lgdi32 -lrpcrt4 -loleaut32 -lws2_32 -lshlwapi -lwindowscodecs 
DYNAMIC := 

EXES := Exe/main.exe
LIBS := 
RESS := 

#--------------------------------------------------------------------------------
# EXE
#--------------------------------------------------------------------------------
.PHONY:exe
exe:$(EXES)

#----------------------------------------
# Exe/main.exe
#----------------------------------------
EXE000_DEPEND := Obj/main.o Obj/game.o Obj/resource.o Obj/constant.o Obj/controll.o Obj/layout.o Obj/0_title/scene_main.o Obj/0_title/scene_game.o Obj/1_game/scene_main.o Obj/1_game/scene_game.o Obj/1_game/scene_frame.o Obj/1_game/frame/radar.o Obj/1_game/frame/status.o Obj/1_game/frame/gauge.o Obj/1_game/frame/face.o Obj/1_game/scene_atari.o Obj/1_game/scene_camera.o Obj/1_game/camera_x.o Obj/1_game/camera_p.o Obj/1_game/scene_grid.o Obj/1_game/grid_m.o Obj/1_game/grid_v.o Obj/1_game/grid_r.o Obj/1_game/grid_d.o Obj/1_game/actor_x.o Obj/1_game/actor_v.o Obj/1_game/actor_a.o Obj/1_game/actor_m.o Obj/1_game/actor_u.o Obj/1_game/aobj.o Obj/1_game/aobj_v.o Obj/1_game/scene_player.o Obj/1_game/player_x.o Obj/1_game/player_v.o Obj/1_game/player_m.o Obj/1_game/player_r.o Obj/1_game/player_d.o Obj/1_game/scene_enemy.o Obj/1_game/enemy_x.o Obj/1_game/enemy_m.o Obj/1_game/enemy_r.o Obj/1_game/enemy_d.o Obj/1_game/enemy/mummy.o Obj/1_game/scene_spell.o Obj/1_game/spell_x.o Obj/1_game/spell_m.o Obj/1_game/spell_r.o Obj/1_game/spell_d.o Obj/1_game/spell/fireball.o Obj/1_game/spell/fireball_v.o Obj/1_game/map.o Obj/1_game/map_data.o

EXE000_OBJECT := ${filter %.o %.ro, $(EXE000_DEPEND)}
Exe/main.exe:$(EXE000_DEPEND) 
	@if [ ! -d Exe/ ]; then mkdir -p Exe/; fi
	$(LD) $(LDFLAGS) -mwindows -static-libgcc -static-libstdc++ -o $@  $(EXE000_OBJECT)  -L./Obj -L../../../Opal/Obj -lgame_dx11 -lgame -ldraw_dx11 -ldraw -ldxtk -ldxtx -lcall -lopal $(LIBRARY)

Obj/main.o:main.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/game.o:game.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/resource.o:resource.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/constant.o:constant.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/controll.o:controll.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/layout.o:layout.cpp 
	@if [ ! -d Obj/ ]; then mkdir -p Obj/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@    $(INCPATH) 

Obj/0_title/scene_main.o:0_title/scene_main.cpp 
	@if [ ! -d Obj/0_title/ ]; then mkdir -p Obj/0_title/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I0_title  $(INCPATH) 

Obj/0_title/scene_game.o:0_title/scene_game.cpp 
	@if [ ! -d Obj/0_title/ ]; then mkdir -p Obj/0_title/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I0_title  $(INCPATH) 

Obj/1_game/scene_main.o:1_game/scene_main.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_game.o:1_game/scene_game.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_frame.o:1_game/scene_frame.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/frame/radar.o:1_game/frame/radar.cpp 
	@if [ ! -d Obj/1_game/frame/ ]; then mkdir -p Obj/1_game/frame/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/frame  -I1_game/ $(INCPATH) 

Obj/1_game/frame/status.o:1_game/frame/status.cpp 
	@if [ ! -d Obj/1_game/frame/ ]; then mkdir -p Obj/1_game/frame/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/frame  -I1_game/ $(INCPATH) 

Obj/1_game/frame/gauge.o:1_game/frame/gauge.cpp 
	@if [ ! -d Obj/1_game/frame/ ]; then mkdir -p Obj/1_game/frame/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/frame  -I1_game/ $(INCPATH) 

Obj/1_game/frame/face.o:1_game/frame/face.cpp 
	@if [ ! -d Obj/1_game/frame/ ]; then mkdir -p Obj/1_game/frame/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/frame  -I1_game/ $(INCPATH) 

Obj/1_game/scene_atari.o:1_game/scene_atari.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_camera.o:1_game/scene_camera.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/camera_x.o:1_game/camera_x.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/camera_p.o:1_game/camera_p.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_grid.o:1_game/scene_grid.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/grid_m.o:1_game/grid_m.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/grid_v.o:1_game/grid_v.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/grid_r.o:1_game/grid_r.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/grid_d.o:1_game/grid_d.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/actor_x.o:1_game/actor_x.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/actor_v.o:1_game/actor_v.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/actor_a.o:1_game/actor_a.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/actor_m.o:1_game/actor_m.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/actor_u.o:1_game/actor_u.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/aobj.o:1_game/aobj.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/aobj_v.o:1_game/aobj_v.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_player.o:1_game/scene_player.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/player_x.o:1_game/player_x.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/player_v.o:1_game/player_v.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/player_m.o:1_game/player_m.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/player_r.o:1_game/player_r.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/player_d.o:1_game/player_d.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/scene_enemy.o:1_game/scene_enemy.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/enemy_x.o:1_game/enemy_x.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/enemy_m.o:1_game/enemy_m.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/enemy_r.o:1_game/enemy_r.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/enemy_d.o:1_game/enemy_d.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/enemy/mummy.o:1_game/enemy/mummy.cpp 
	@if [ ! -d Obj/1_game/enemy/ ]; then mkdir -p Obj/1_game/enemy/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/enemy  -I1_game/ $(INCPATH) 

Obj/1_game/scene_spell.o:1_game/scene_spell.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/spell_x.o:1_game/spell_x.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/spell_m.o:1_game/spell_m.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/spell_r.o:1_game/spell_r.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/spell_d.o:1_game/spell_d.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/spell/fireball.o:1_game/spell/fireball.cpp 
	@if [ ! -d Obj/1_game/spell/ ]; then mkdir -p Obj/1_game/spell/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/spell  -I1_game/ $(INCPATH) 

Obj/1_game/spell/fireball_v.o:1_game/spell/fireball_v.cpp 
	@if [ ! -d Obj/1_game/spell/ ]; then mkdir -p Obj/1_game/spell/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game/spell  -I1_game/ $(INCPATH) 

Obj/1_game/map.o:1_game/map.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 

Obj/1_game/map_data.o:1_game/map_data.cpp 
	@if [ ! -d Obj/1_game/ ]; then mkdir -p Obj/1_game/; fi
	$(CC)  $< $(CPPFLAGS) -c -o $@   -I1_game  $(INCPATH) 


#--------------------------------------------------------------------------------
# LIB
#--------------------------------------------------------------------------------
.PHONY:lib
lib:$(LIBS)



#--------------------------------------------------------------------------------
# RES
#--------------------------------------------------------------------------------
.PHONY:res
res:$(RESS)



#================================================================================
# EOF
#================================================================================

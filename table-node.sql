-- auto-generated definition
create table node
(
    id                   integer
        constraint node_pk
            primary key,
    Lo_x                 real,
    Lo_y                 real,
    Lo_z                 real,
    wo_x                 real,
    wo_y                 real,
    wo_z                 real,
    pos_out_x            real,
    pos_out_y            real,
    pos_out_z            real,
    inter_happened       integer,
    inter_pos_x          real,
    inter_pos_y          real,
    inter_pos_z          real,
    Li_light_x           real,
    Li_light_y           real,
    Li_light_z           real,
    wi_light_x           real,
    wi_light_y           real,
    wi_light_z           real,
    inter_light_happened integer,
    inter_light_pos_x    real,
    inter_light_pos_y    real,
    inter_light_pos_z    real,
    Li_obj_x             real,
    Li_obj_y             real,
    Li_obj_z             real,
    wi_obj_x             real,
    wi_obj_y             real,
    wi_obj_z             real,
    inter_obj_happened   integer,
    inter_obj_pos_x      real,
    inter_obj_pos_y      real,
    inter_obj_pos_z      real,
    RR                   real,
    obj_is_emission      integer
);

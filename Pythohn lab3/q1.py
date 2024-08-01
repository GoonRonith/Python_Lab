def check_season(month):
    seasons={
        "winter":['december','january','february'],
        "spring":['march','april'],
        "summer":['may','june','july','august'],
        "autumn":['september','october','november']
        }
    for season in seasons:
        for m in seasons[season]:
            if(m==month): return season
    return "invalid month"
            

print(check_season('february'))
import { BrowserModule } from '@angular/platform-browser';
import { NgModule, Pipe, PipeTransform } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { HttpModule, JsonpModule } from '@angular/http';



// Components
import { AppComponent } from './app.component';
import { HeaderComponent } from './components/header/header.component';
import { SidebarComponent } from './components/sidebar/sidebar.component'
import { DevicesComponent } from './components/devices/devices.component';
import { LoginComponent } from './components/login/login.component';
import { SignupComponent } from './components/signup/signup.component';
import { StatusComponent } from './components/status/status.component';
import { AgmCoreModule } from '@agm/core';




// Services
import { IBMIoTPService } from './services/iotp/ibmIoTP.service'
import { LiveDataService } from './services/livedata/liveData.service'
import { apiCallServer } from './services/apicallserver/apiCallServer.service'

// Routing
import { routing } from './app.routes';


@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    SidebarComponent,
    DevicesComponent,
    StatusComponent,
    SignupComponent,
    LoginComponent

  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpModule,
    JsonpModule,
    routing,
    AgmCoreModule.forRoot({
      apiKey: 'AIzaSyBWR5HzlxmdF0222bZzySFSyM9vLKTjK9I'
    })
  ],
  providers: [
    IBMIoTPService,
    LiveDataService,
    apiCallServer
  ],
  bootstrap: [
    AppComponent
  ]
})
export class AppModule { }